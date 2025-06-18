#include <iostream>
using namespace std;
/*
 - I have create a student class
 - You can create Car class as well
 - Employee class is also suitable etc..
*/

class Student
{
    // class is user defined data type
    // empty class take 1B . Padding is also used for size of class

private:
    string name;
    int roll_number;
    int age;
    char grade;

public:
    // setter
    void setName(string Student_name)
    {
        // validation of name
        if (Student_name == "")
        {
            cout << "Name can't be empty . Please fill correct name " << endl;
            return;
        }
        this->name = Student_name;
    }
    void setAge(int Student_age)
    {
        if (Student_age > 0 && Student_age <= 18)
        { // suppose this is for school website
            this->age = Student_age;
        }
        else
        {
            cout << "Please enter correct age. " << endl;
            return;
        }
    }

    void setGrade(char Student_grade)
    {
        if (Student_grade < 'A' || Student_grade > 'F')
        {
            cout << "Invalid grade. Please enter a valid grade (A-F)." << endl;
            return;
        }

        this->grade = Student_grade;
    }

    // roll number
    void setRollNumber(int Student_roll)
    {
        if (Student_roll > 0 && Student_roll < 500)
        { // let's suppose we have 500 student right now
            this->roll_number = Student_roll;
        }
        else
        {
            cout << "Please enter roll number correctly. Between 1-500 " << endl;
            return;
        }
    }

    // getter

    // name
    string getName()
    {
        return name;
    }

    // age
    int getAge()
    {
        return age;
    }

    // roll
    int getRoll()
    {
        return roll_number;
    }

    // grade
    char getGrade()
    {
        return grade;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll_number << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main()
{
    Student s1;
    s1.setName("Satyendra");
    s1.setAge(15);         // age 1-18
    s1.setRollNumber(100); // roll 1-500
    s1.setGrade('C');

    // get name
    /*
    cout << "Name: " << s1.getName() << endl;
    cout << "Roll Numbe:r " << s1.getRoll() << endl;
    cout << "Age: " << s1.getAge() << endl;
    cout << "Grade: " << s1.getGrade() << endl;
    */

    // get details by method
    s1.display();
    return 0;
}