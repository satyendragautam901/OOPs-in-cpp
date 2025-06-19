#include <iostream>
using namespace std;

/*
Single Inheritance - Child class inherits characteristic and behaviour from single class not more than One.
Note.                 1. First parent class constructor is called then child class and reverse for destructor calling.
*/

class Human
{
protected:
    string name;
    int age;

public:
    void PrintParent()
    {
        cout << "Parent class . " << endl;
    }

    void Display()
    {
        cout << "Display method of Parent class . " << endl;
    }

    // parent constructor
    Human()
    {
        cout << "Default constructor of Parent class " << endl;
    }
    Human(const string &name, int age)
    {
        cout << "Parametrised constructor of Parent class " << endl;
        this->name = name;
        this->age = age;
    }

    ~Human()
    {
        cout << "Destructor of Parent called" << endl;
    }
};

class Engineer : public Human
{
private:
    string companyName;
    int yearOfExperience;

public:
    /*

    Engineer(const string &name, const string & companyName, int age, int yearOfExp){
        cout<<"Paramertrised constructor of child class "<<endl;
        this->name = name;
        this->companyName = companyName;
        this->age = age;
        this->yearOfExperience = yearOfExp;
    }
    */

    // we can call parent class constructor
    Engineer(const string &name, const string &companyName, int age, int yearOfExp) : Human(name, age)
    {
        cout << "Paramertrised constructor of child class " << endl;

        this->companyName = companyName;

        this->yearOfExperience = yearOfExp;
    }

    void Display()
    { // if display is not define here then parent display method will called.
        cout << "Display method of Child class . " << endl;
        cout << "=========================" << endl;
        cout << "Name is : " << name << endl;
        cout << "Company name is : " << companyName << endl;
        cout << "Year of Experience : " << yearOfExperience << endl;
    }

    ~Engineer()
    {
        cout << "Destructor of Child called" << endl;
    }
};

int main()
{
    Engineer e1("Gautam", "Slay-e", 20, 1);
    e1.Display();
    cout<<"==================="<<endl;
    return 0;
}