#include<iostream>
using namespace std;
/*
Abstract Class - A class with some pure virtual function .
Real life analogy : Let's you are owner Brand A(famous brand) and everyone wants to share your franchise but you have condition these items must be taken from me. 
*/
class Car{
    bool isEngineOn;
    string name;
    public:
        Car(string name): name(name){
            isEngineOn = false;
        }
        void StartEngine(){ // start and stop of car be same.
            isEngineOn = true;
            cout<<"Car Engine started "<<endl;
        }
        void StopEngine(){
            isEngineOn = false;
            cout<<"Car Engine stop "<<endl;
        }

        virtual void ChangeGear() = 0; // change gear and accelerate depend on car type and brand.
        virtual void Accelerate() = 0; // pure virtual function

        ~Car(){
            cout<<"Destructor of car "<<endl;
        }
};

class Scorpio : public Car {
public:
    Scorpio(string name) : Car(name) {}

    void ChangeGear() override {
        cout << "Scorpio gear changed manually." << endl;
    }

    void Accelerate() override {
        cout << "Scorpio accelerating fast..." << endl;
    }

    ~Scorpio() {
        cout << "Destructor of Scorpio" << endl;
    }
};

int main()
{
    // Car c1("Scorpio"); . object of abstract type can't be created . you have to inherits it to another class for this .
    Car* myCar = new Scorpio("Black Color Scorpio"); // base class pointer to derived class object

    myCar->StartEngine();
    myCar->ChangeGear();
    myCar->Accelerate();
    myCar->StopEngine();

    delete myCar;
  return 0;
}