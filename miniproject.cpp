#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <iomanip>

using namespace std;

// ---------- Custom exception ----------
class EnergyException : public runtime_error {
public:
    explicit EnergyException(const string& msg) : runtime_error(msg) {}
};

// ---------- Solar panel (encapsulated) ----------
class SolarPanel {
private:
    string id;
    double capacityKw;      // peak capacity
    double efficiency;      // 0..1

public:
    SolarPanel() : id("UNKNOWN"), capacityKw(0), efficiency(0) {}
    SolarPanel(const string& id_, double cap, double eff)
        : id(id_), capacityKw(cap), efficiency(eff) {
        if (cap <= 0) throw EnergyException("Panel " + id_ + ": capacity must be positive");
        if (eff <= 0 || eff > 1) throw EnergyException("Panel " + id_ + ": efficiency must be in (0,1]");
    }
    const string& getId() const { return id; }
    double getCapacity() const { return capacityKw; }

    // Function overloading: generate(sunlightFactor) and generate(sunlightFactor, cloudCover)
    double generate(double sunlight) const {
        if (sunlight < 0 || sunlight > 1) throw EnergyException("Sunlight factor out of range");
        return capacityKw * efficiency * sunlight;
    }
    double generate(double sunlight, double cloudCover) const {
        if (cloudCover < 0 || cloudCover > 1) throw EnergyException("Cloud cover out of range");
        return generate(sunlight) * (1.0 - cloudCover);
    }
};

// ---------- Battery (encapsulated) ----------
class Battery {
private:
    double capacityKwh;
    double charge;

public:
    Battery(double cap = 50.0, double initial = 10.0) : capacityKwh(cap), charge(initial) {
        if (cap <= 0 || initial < 0 || initial > cap)
            throw EnergyException("Invalid battery parameters");
    }
    double getCharge() const { return charge; }
    double getCapacity() const { return capacityKwh; }

    // returns energy actually stored
    double store(double kwh) {
        if (kwh < 0) throw EnergyException("Cannot store negative energy");
        double space = capacityKwh - charge;
        double stored = min(space, kwh);
        charge += stored;
        return stored;
    }
    // returns energy actually delivered
    double discharge(double kwh) {
        if (kwh < 0) throw EnergyException("Cannot discharge negative energy");
        double given = min(charge, kwh);
        charge -= given;
        return given;
    }
};

// ---------- Load (consumer) ----------
struct Load {
    string name;
    double demandKw;
    int priority;   // 1 = highest priority
};

// ---------- Hourly result record ----------
struct HourReport {
    int hour;
    double generation, demand, served, unmet, curtailed, batteryCharge;
};

// ---------- Microgrid ----------
class Microgrid {
private:
    vector<SolarPanel> panels;
    vector<Load> loads;
    Battery battery;
    map<string, double> energyPerLoad;   // total kWh delivered to each load
    vector<HourReport> reports;

public:
    Microgrid(const Battery& b) : battery(b) {}

    void addPanel(const SolarPanel& p) { panels.push_back(p); }
    void addLoad(const Load& l) {
        if (l.demandKw < 0) throw EnergyException("Load " + l.name + ": negative demand");
        loads.push_back(l);
        energyPerLoad[l.name] = 0.0;
    }

    // Overloaded simulation: sunlight only
    void simulateHour(int hour, double sunlight) { simulateHour(hour, sunlight, 0.0); }

    // Overloaded simulation: sunlight + cloud cover
    void simulateHour(int hour, double sunlight, double cloud) {
        if (panels.empty()) throw EnergyException("No solar panels in the microgrid");

        double generation = 0;
        for (const auto& p : panels) generation += p.generate(sunlight, cloud);

        // Sort loads by priority (algorithm)
        vector<Load> sorted = loads;
        sort(sorted.begin(), sorted.end(),
             [](const Load& a, const Load& b) { return a.priority < b.priority; });

        double demand = accumulate(sorted.begin(), sorted.end(), 0.0,
                                   [](double s, const Load& l) { return s + l.demandKw; });

        double available = generation;   // 1 hour => kW == kWh
        double served = 0;

        // Energy allocation: solar first, then battery, by priority
        for (const auto& l : sorted) {
            double need = l.demandKw;
            double fromSolar = min(available, need);
            available -= fromSolar;
            need -= fromSolar;
            double fromBattery = 0;
            if (need > 0) fromBattery = battery.discharge(need);
            double delivered = fromSolar + fromBattery;
            energyPerLoad[l.name] += delivered;
            served += delivered;
        }

        // Surplus solar charges the battery; leftover is curtailed
        double stored = battery.store(available);
        double curtailed = available - stored;

        reports.push_back({hour, generation, demand, served, demand - served,
                           curtailed, battery.getCharge()});
    }

    void printReport() const {
        cout << "\n=========== HOURLY ENERGY REPORT ===========\n";
        cout << left << setw(6) << "Hour" << setw(10) << "Gen(kW)" << setw(11) << "Demand(kW)"
             << setw(10) << "Served" << setw(9) << "Unmet" << setw(11) << "Curtailed"
             << setw(10) << "Battery" << "\n";
        cout << string(67, '-') << "\n" << fixed << setprecision(2);
        for (const auto& r : reports) {
            cout << left << setw(6) << r.hour << setw(10) << r.generation << setw(11) << r.demand
                 << setw(10) << r.served << setw(9) << r.unmet << setw(11) << r.curtailed
                 << setw(10) << r.batteryCharge << "\n";
        }

        cout << "\n----------- ENERGY PER LOAD (kWh) -----------\n";
        for (const auto& kv : energyPerLoad)
            cout << left << setw(15) << kv.first << kv.second << "\n";

        auto peak = max_element(reports.begin(), reports.end(),
            [](const HourReport& a, const HourReport& b) { return a.generation < b.generation; });
        double totalGen = 0, totalUnmet = 0, totalCurt = 0;
        for (const auto& r : reports) { totalGen += r.generation; totalUnmet += r.unmet; totalCurt += r.curtailed; }

        cout << "\n------------------ SUMMARY ------------------\n";
        cout << "Total generation : " << totalGen << " kWh\n";
        cout << "Total unmet load : " << totalUnmet << " kWh\n";
        cout << "Total curtailed  : " << totalCurt << " kWh\n";
        cout << "Peak generation  : " << peak->generation << " kW at hour " << peak->hour << "\n";
        cout << "Final battery    : " << battery.getCharge() << " / " << battery.getCapacity() << " kWh\n";
    }

    // File I/O: write report
    void saveReport(const string& filename) const {
        ofstream out(filename);
        if (!out) throw EnergyException("Cannot open file for writing: " + filename);
        out << "hour,generation,demand,served,unmet,curtailed,battery\n" << fixed << setprecision(2);
        for (const auto& r : reports)
            out << r.hour << "," << r.generation << "," << r.demand << "," << r.served << ","
                << r.unmet << "," << r.curtailed << "," << r.batteryCharge << "\n";
    }
};

// File I/O: read sunlight profile (hour,sunlight,cloud) from file
vector<array<double, 3>> loadWeather(const string& filename) {
    ifstream in(filename);
    if (!in) throw EnergyException("Cannot open weather file: " + filename);
    vector<array<double, 3>> data;
    string line;
    getline(in, line);   // skip header
    while (getline(in, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string a, b, c;
        getline(ss, a, ','); getline(ss, b, ','); getline(ss, c, ',');
        try {
            data.push_back({stod(a), stod(b), stod(c)});
        } catch (const exception&) {
            throw EnergyException("Malformed line in weather file: " + line);
        }
    }
    return data;
}

int main() {
    // Create sample weather input file
    {
        ofstream w("weather.csv");
        w << "hour,sunlight,cloud\n"
          << "6,0.20,0.00\n7,0.40,0.10\n8,0.60,0.00\n9,0.80,0.10\n10,0.95,0.00\n"
          << "11,1.00,0.20\n12,1.00,0.00\n13,0.90,0.30\n14,0.70,0.10\n15,0.50,0.00\n"
          << "16,0.30,0.20\n17,0.10,0.00\n18,0.00,0.00\n";
    }

    try {
        Microgrid grid(Battery(40.0, 8.0));
        grid.addPanel(SolarPanel("PV-1", 20.0, 0.90));  
        grid.addPanel(SolarPanel("PV-2", 15.0, 0.85));
        grid.addLoad({"Hospital", 5.0, 1});
        grid.addLoad({"Water Pump", 3.0, 2});
        grid.addLoad({"Households", 6.0, 3});
        grid.addLoad({"Street Lights", 2.0, 4});

        auto weather = loadWeather("weather.csv");
        for (const auto& w : weather) {
            int hour = static_cast<int>(w[0]);
            if (w[2] > 0) grid.simulateHour(hour, w[1], w[2]);   // overload 2
            else          grid.simulateHour(hour, w[1]);         // overload 1
        }

        grid.printReport();
        grid.saveReport("microgrid_report.csv");
        cout << "\nReport saved to microgrid_report.csv\n";

        // Demonstrate exception handling
        cout << "\n--- Exception handling demo ---\n";
        try {
            SolarPanel bad("PV-BAD", -5.0, 0.8);
        } catch (const EnergyException& e) {
            cout << "Caught: " << e.what() << "\n";
        }
        try {
            loadWeather("missing.csv");
        } catch (const EnergyException& e) {
            cout << "Caught: " << e.what() << "\n";
        }
    } catch (const EnergyException& e) {
        cerr << "Simulation error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
