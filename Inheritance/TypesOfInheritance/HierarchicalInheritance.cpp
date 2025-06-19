#include <iostream>
using namespace std;

/*
Hierarchical Inheritance - Single Parent class and many Child class.

*/

class Human
{
protected:
    string name;
    int age;

public:
    void Display()
    {
        cout << "Display method of Parent class . " << endl;
    }

    ~Human()
    {
        cout << "Destructor of Parent called" << endl;
    }
};

// class 1 from Human class.
class Engineer : public Human
{
private:
    string companyName;
    int yearOfExperience;

public:
    Engineer(const string &name, const string &companyName, int age, int yearOfExp)
    {
        this->name = name;
        this->companyName = companyName;
        this->age = age;
        this->yearOfExperience = yearOfExp;
    }

    void Display()
    {
        cout << "Engineer Name is : " << name << endl;
        cout << "Company name is : " << companyName << endl;
        cout << "Year of Experience : " << yearOfExperience << endl;
    }

    ~Engineer()
    {
        cout << "Destructor of Engg called" << endl;
    }
};

// class 2 from human class

class Student : public Human
{
private:
    string className;
    int rollNumber;

public:
    Student(const string &studentName, const string &className, int age, int rollNumber)
    {
        this->name = studentName;
        this->className = className;
        this->age = age;
        this->rollNumber = rollNumber;
    }

    void Display()
    { // if display is not define here then parent display method will called.

        cout << "Student Name is : " << name << endl;
        cout << "Class name is : " << className << endl;
        cout << "Roll Number is : " << rollNumber << endl;
    }

    ~Student()
    {
        cout << "Destructor of student " << endl;
    }
};

// class 3. This is 3rd class from Human
class Teacher : public Human
{
private:
    string subjectTaught;

public:
    Teacher(const string &name, const string &subject, int age)
    {
        this->name = name;
        this->subjectTaught = subject;
        this->age = age;
    }

    void Display()
    { // if display is not define here then parent display method will called.

        cout << "Teacher Name is : " << name << endl;
        cout << "Subject taught is : " << subjectTaught << endl;
        
    }

    ~Teacher(){
        cout<<"Destructor of Teacher "<<endl;
    }
};

int main()
{
    Engineer e1("Gautam", "Slay-e", 20, 1);
    e1.Display();
    cout << "===================" << endl;

    Student s1("Adi", "Ninth", 15, 150);
    s1.Display();
    cout << "===================" << endl;

    Teacher t1("Ram Sir", "Mathematics",45);
    t1.Display();
    cout << "===================" << endl;
    return 0;
}