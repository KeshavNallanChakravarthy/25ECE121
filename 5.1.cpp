//one shared copy must be defined outside the class
//a static data member is shared by all objects of class
//used as common counter in this program to count the current existing objects

#include <iostream>
using namespace std;

class widget{

    int id;
    static int count;

    public: widget() {id = ++count; cout<< "created W"<<id<<endl;}
            ~widget(){--count; cout<<"destroyed W"<<id<<endl;}
            static int alive(){return count;}
};
int widget::count = 0;

int main(){
    widget a, b;
    cout<<"alive ="<<widget::alive()<<endl;
    {widget c; cout<<"alive "<<widget::alive()<<endl;}
    cout<<"alive ="<<widget::alive()<<endl;
    return 0;
}
