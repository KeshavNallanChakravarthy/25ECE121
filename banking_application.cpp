#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    private:
        // Data member
        string owner;
        double balance;

    public:
        // member fxn to open acc.
        void OpenAccount(string name, double initial) 
             {
                owner = name;
                if(initial > 0)
                    balance = initial;
                else 
                    balance = 0;
             }
        //member fxn to deposit money
        void deposit (double amount) 
             {
                if(amount>0)
                {
                    balance = balance + amount;
                    
                }
             }
        
        

        bool withdraw(double amount) 
             {
                if(amount > 0 && amount <= balance)
                    {
                        balance = balance - amount;
                        return true;
                    }
                    return false;    
             }
        string getOwner()
             {
                return owner;
             }
        double getBalance()
             {
                return balance;
             }

};

int main()
{
    BankAccount account;
    string name;
    double initialDeposit;
    double depositAmount;
    double validWithdraw;

    //acc. holder name
    cout<<"enter account holder name: ";
    getline(cin, name);

    //initial deposit
    cout<<"enter initial deposit: ";
    cin>>initialDeposit;
    account.OpenAccount(name, initialDeposit);

    //Deposit
    cout<<"enter amount to deposit: ";
    cin>>depositAmount;
    account.deposit(depositAmount);

    //valid withdrawal
    cout<<"\nEnter valid withdrawal amount: ";
    cin>>validWithdraw;
    if(account.withdraw(validWithdraw))
        {
            cout<<"withdraw sucessful"<<endl;
        }
    else
        {
            cout<<"withdraw failed"<<endl;
        }

    // display account details
    cout<<"account holder: " << account.getOwner()<<endl;
    cout<<"final balance: "<< account.getBalance()<<endl;

    return 0;
}

