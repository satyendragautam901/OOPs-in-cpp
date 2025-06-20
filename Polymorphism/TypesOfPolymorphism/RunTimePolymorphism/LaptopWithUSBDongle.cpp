#include<iostream>
using namespace std;
/*
 let's you have A USB dongle for wireless mouse. I you have HP laptop simply insert and use with HP laptop.
 If You have Dell laptop insert and use with Dell. This will define at use time that which brand laptop is. same as run time polymorphism
*/
class Laptop {
public:
    
    virtual void AcceptInputDevice() {
        cout << "Laptop accepts device" << endl;
    }
};

class Dell : public Laptop {
public:
    
    void AcceptInputDevice() override {
        cout << "Dell using USB Dongle" << endl;
    }
};

class HP : public Laptop {
public:
   
    void AcceptInputDevice() override {
        cout << "HP using USB Dongle" << endl;
    }
};



int main()
{
    Laptop *meraLaptop = new Dell;
    meraLaptop->AcceptInputDevice();

    meraLaptop = new HP;
    meraLaptop->AcceptInputDevice();

    
  return 0;
}