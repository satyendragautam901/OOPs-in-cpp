#include <iostream>
using namespace std;
class Car
{
private:
    // car have car name , car brand and it manufacturing date .

    string carName;
    string carBrand;
    int manufacturingYear;

public:
    // set car name
    void setCarName(string name)
    {
        if (name == "")
        {
            cout << "Car Name can't be empty " << endl;
            return;
        }
        this->carName = name;
    }

    // set car brand
    void setCarBrand(string brand)
    {
        if (brand == "")
        {
            cout << "Car must have a brand name " << endl;
            return;
        }
        this->carBrand = brand;
    }

    // set manufacturing date
    void setManYear(int year)
    {
        if (year <= 1900 || year > 2025)
        {
            cout << "Please enter a valid manufacturing year (1900 - 2025)" << endl;
            return;
        }

        this->manufacturingYear = year;
    }

    // getter
    void DisplayCarDetails(int passkey)
    { // passkey is used to verify that this user has authority for display method

        if (passkey == 2580)
        {
            cout << "Car name is : " << carName << endl;
            cout << "Car brand is : " << carBrand << endl;
            cout << "Year of Manufacturing is : " << manufacturingYear << endl;
        }
        else
        {
            cout << "Please enter pass key for display method " << endl;
        }
    }
};
int main()
{
    
    /*

    Car MyCar;
    MyCar.setCarBrand("Toyota");
    MyCar.setCarName("Fortuner");
    MyCar.setManYear(2020);
    */

    // create car dynamic
    Car *MyCar = new Car;
    MyCar->setCarBrand("Toyota"); // same as (*MyCar).setCarBrand("Toyota");
    MyCar->setCarName("Fortuner");
    MyCar->setManYear(2020);

    // access car behaviour
    // (*MyCar).DisplayCarDetails();

    MyCar->DisplayCarDetails(2580); // access car behaviour . same as above
    return 0;
}