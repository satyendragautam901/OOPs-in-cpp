#include <iostream>
using namespace std;

class Employee
{
private:
    int empId;
    string empName;
    string empAddress;
    ;

public:
    Employee()
    { // this is default constructor . It basically needn't to define
        cout << "Default Constructor is Called " << endl;
    }

    // parametrised constructor
    Employee(int empId, string empName, string empAddress = "India")
    { // address is default
        cout << "Parametrised Constructor is Called " << endl;
        setEmpId(empId);
        setEmpName(empName);
        setEmpAddress(empAddress);
    }

    // copy constructor
    Employee(const Employee &e) // const to accidently modification
    {
        cout << "Copy constructor is called " << endl;
        empId = e.empId;
        empName = e.empName;
        empAddress = e.empAddress;
    }

    // constructor overloading
    Employee(int empId): empId(empId), empName("Unknown"), empAddress("India, Apna Pradesh UP") {
        cout<<"Overload constructor is called "<<endl;
    }

    // set empId
    void setEmpId(int empId)
    {
        if (empId <= 0 || empId > 1000)
        {
            cout << "Please Enter correct employee ID (1-1000)" << endl;
            return;
        }

        this->empId = empId;
    }

    // set empName
    void setEmpName(string empName)
    {
        if (empName == "")
        {
            cout << "Employee name can't be empty. Please enter Name ." << endl;
            return;
        }
        this->empName = empName;
    }

    void setEmpAddress(string empAddress)
    {
        if (empAddress == "")
        {
            cout << "Please Enter Address , it can't be Empty " << endl;
            return;
        }
        this->empAddress = empAddress;
    }

    // display employee details
    void Display()
    {
        cout << "Employee name: " << empName << endl;
        cout << "Employee id: " << empId << endl;
        cout << "Employee address: " << empAddress << endl;
    }

    // destructor
    /*
    Destrutor is delete resources, like the file which constructor open or release memory if it was dynamically created.
    Destructor is not delete onject . because object is reside in stack so when program goes out of(scope) main then it will destroy.
    
    Destructor is automatically called when the object goes out of scope.
    For dynamic objects (`new`), you must use `delete` to trigger the destructor.

    Destructor cleans up resources like memory, file handles, etc.
    */

    

    ~Employee()
    {
        // execution of destructor is in reverse . like if 1,2,3 constructor is called . so desctructor will be called like 3,2,1
        cout << "Destructor is called . Now dynamic memory released " << empName << endl;
    }
};
int main()
{
    Employee e1(123, "Rohan", "UP India");
    e1.Display();

    // copy constructor
    cout << "=====================" << endl;
    Employee e2(e1);
    e2.Display();
    cout << "=====================" << endl;
    // 3rd employee
    Employee e3(100, "Mohan");
    e3.Display();
    cout << "=====================" << endl;
    // constructor overloading
    Employee e5(159);
    e5.Display();
    cout << "=====================" << endl;
    // dynamic creation
    Employee *e4 = new Employee(158, "Ram");
    // if dynamic allocation then this way to release memory
    delete e4;
    return 0;
}