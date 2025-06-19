#include <iostream>
using namespace std;

/*
Multi Level Inheritance - Child class inherits characteristic and behaviour from it's above class and it will inherits from another class.
    3(parent)---->2(parent/child)----->1(child)
    2 . works for parent for 1 and child for 3.
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

    ~Human()
    {
        cout << "Destructor of Human class " << name<<endl;
    }
};

class Employee : public Human
{
protected:
    string companyName;
    int yearOfExperience;

public:
    Employee(const string &name, const string &companyName, int age, int yearOfExp)
    {
        cout << "Paramertrised constructor of employee class " << endl;
        this->name = name;
        this->companyName = companyName;
        this->age = age;
        this->yearOfExperience = yearOfExp;
    }

    void Display()
    { // if display is not define here then parent display method will called.
        cout << "Display method of employee class . " << endl;
        cout << "=========================" << endl;
        cout << "Employee Name is : " << name << endl;
        cout << "Company name is : " << companyName << endl;
        cout << "Year of Experience : " << yearOfExperience << endl;
    }

    ~Employee()
    {
        cout << "Destructor of employee class " <<name<< endl;
    }
};

class Manager : protected Employee
{
protected:
    int numberOfEmployee; // number of employees under the manager
    string deptName;

public:
    Manager(const string &name, const string &companyName, const string &deptName, int age, int yearOfExp, int employees)
        : Employee(name, companyName, age, yearOfExp), deptName(deptName), numberOfEmployee(employees)
    {
    }

    void Display()
    { // if display is not define here then parent display method will called.
        cout << "Display method of manager class . " << endl;
        cout << "=========================" << endl;
        cout << "Manager Name is : " << name << endl;
        cout << "Company name is : " << companyName << endl;
        cout << "Year of Experience : " << yearOfExperience << endl;
        cout<<"Department name : "<<deptName<<endl;
        cout<<"Number of employee under this manager : "<<numberOfEmployee<<endl;
    }

    ~Manager()
    {
        cout << "Destructor of manager class " << name<<endl;
    }
};

int main()
{
    Employee e1("Gautam", "Slay-e", 20, 1);
    e1.Display();
    cout << "===================" << endl;

    // create an object of manager 
    Manager m1("Vipin", "Googleee","IT", 30,5,500);
    m1.Display();
    cout << "===================" << endl;
    return 0;
}