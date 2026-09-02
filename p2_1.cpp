#include <iostream>
using namespace std;

int area(int side){
    return side*side;
}

int area(int length, int breadth){
    return length*breadth;
}

float area(double height, double base){
    return 0.5*(height*base);
}


int main(){

    int side;
    cout<<"Enter side of a square: ";
    cin>>side;
    cout<<"Area of square: "<<area(side)<<endl;

    int length, breadth;
    cout<<"Enter length and breadth of a rectangle: ";
    cin>>length>>breadth;
    cout<<"Area of rectangle: "<<area(length,breadth)<<endl;

    double height, base;
    cout<<"Enter height and base of triangle: "<<endl;
    cin>>height>>base;
    cout<<"Area of triangle: "<<area(height,base)<<endl;

    return 0;

    //same fxn doing diff tasks => operator overloading 


}