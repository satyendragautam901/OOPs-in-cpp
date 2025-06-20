#include <iostream>
using namespace std;
/*
function overloading - Same function name with different arguments. Resolved at compile time.
*/

class Car
{
private:
  bool isEngineOn;
  int currentSpeed;
  int currentGear;
  string carBrand;

public:
  Car(const string &name) : carBrand(name)
  {
    isEngineOn = false;
    currentGear = 0;
    currentSpeed = 0;
  }

  // start engine
  void startEngine()
  { // i don't want to go for more validation.
    isEngineOn = true;
    cout << "Engine started . " << endl;
  }
  // stop engine
  void stopEngine()
  {
    isEngineOn = false;
    cout << "Engine stoped . " << endl;
  }

  // here change hear function is overload.

  void changeGear()
  { // a user have ability to go directly any gear.
    if (!isEngineOn)
    {
      cout << "Please start engine first " << endl;
      return;
    }
    else
    {
      if (currentGear >= 4)
      {
        cout << "Cannot exceed max gear. Current gear is: " << currentGear << endl;
        return;
      }
      else
      {
        currentGear++;
        currentSpeed = currentSpeed + currentGear * 20;
        cout << carBrand << " - Gear: " << currentGear << " | Speed: " << currentSpeed << "km/h" << endl;
      }
    }
  }

  void changeGear(int gear)
  { // a user have ability to go directly any gear.
    if (!isEngineOn)
    {
      cout << "Please start engine first " << endl;
      return;
    }
    else
    {
      if (currentGear + gear > 4)
      {
        cout << "Cannot exceed max gear. Current gear is: " << currentGear << endl;
        return;
      }

      else
      {
        currentGear += gear;
        currentSpeed = currentSpeed + gear * 20;
        cout << carBrand << " - Gear: " << currentGear << " | Speed: " << currentSpeed << "km/h" << endl;

      }
    }
  }

  ~Car()
  {
    cout << "Car desructor " << carBrand << endl;
  }
};
int main()
{
  Car c1("Totota");
  c1.startEngine();
  c1.changeGear(4);
  c1.changeGear();
  c1.stopEngine();
  return 0;
}