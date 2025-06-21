#include<iostream>
using namespace std;
/*
Interface - All the member function of class must be virtual.
*/
class ICar{
    protected:
        bool isEngineOn;
        string name;
    public:
        
        virtual void StartEngine() = 0;
        virtual void StopEngine() = 0 ;

        virtual void ChangeGear() = 0; // change gear and accelerate depend on car type and brand.
        virtual void Accelerate() = 0;

       virtual ~ICar(){
            cout<<"Destructor of car "<<endl;
        }
};

class Scorpio : public ICar {
public:
    Scorpio(string name) {
        this->name = name;
    }
    void StartEngine() override{ // start and stop of car be same.
            isEngineOn = true;
            cout<<"Car Engine started "<<endl;
        }
        void StopEngine() override{
            isEngineOn = false;
            cout<<"Car Engine stop "<<endl;
        }

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
    ICar *ptr = new Scorpio("Black Scorpio");
    ptr->StartEngine();
    ptr->ChangeGear();
    ptr->Accelerate();
    ptr->StopEngine();

    delete ptr;
  return 0;
}