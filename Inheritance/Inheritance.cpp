#include<iostream>
using namespace std;

/* Inheritance -  A way to derive / inherit characteristic and behaviour from parent class / another class.
    Parent / Super / Base class same terminology used.
    Child / Sub / Derive class same terminology.
    we are create a Human class , student , teacher , driver etc.... everyone be a object of human class..

*/

class Human{
    /*
    If private is used here, child classes can't inherit its characteristics like name, age, and weight
    Protected member can only be accessible in sub class not outside the class like form main(client code) . so it's better to use this.
    */
    protected:

        // assume only three characteristic right now.
        string name;
        int age;
        int weight;
};

// A Student is a type of Human, so it can inherit common attributes like name, age, and weight.
class Student : public Human{
    /*
    While inheriting a class, you can use access modifiers like "public, protected, or private" to control the visibility of inherited members.

    1. If Public - All the data members of parent class become public in child class. if data member is defined public .
                if Data member is defined as protected then it will be protected in child class.

    2. If Protected - All the data members of parent class become protected.

    3. If Private - All the data members of parent class become private.

    */

    // <-------------------- apart from name, age, and weight a student have roll number, class name etc..----------------->
    private:
        int roll_number;
        string className;

    public:
        Student(string name, int age, int weight, int roll, string nameOfClass){
            // We could also use setters/getters for better encapsulation instead of directly assigning.

            this->name = name;
            this->age = age;
            this->weight = weight;
            this->roll_number = roll;
            this->className = nameOfClass;
        }

        void Print(){
            cout<<"Student name is : "<<name<<endl;
            cout<<"Age is : "<<age<<endl;
            cout<<"Roll number is : "<<roll_number<<endl;
            cout<<"Class in : "<<className<<endl;

            cout<<"Thank You!!!!"<<endl;
        }

        ~Student(){
            cout<<"Student \'"<<name<<"\' instance deleted "<<endl;
        }
};

class Teacher : private Human{
    private:
        string subjectTeach;
        int teachingExperience;

    public:
        Teacher(string name, int age, int weight, int teachingExperience, string subjectTeach){
            // We could also use setters/getters for better encapsulation instead of directly assigning. 
            
            this->name = name;
            this->age = age;
            this->weight = weight;
            this->teachingExperience = teachingExperience;
            this->subjectTeach = subjectTeach;
        }

        void Print(){
            cout<<"Teacher name is : "<<name<<endl;
            cout<<"Age is : "<<age<<endl;
            cout<<"Experience is : "<<teachingExperience<<endl;
            cout<<"Stubject is : "<<subjectTeach<<endl;

            cout<<"Thank You!!!!"<<endl;
        }

        ~Teacher(){
            
            cout<<"Teacher \'"<<name<<"\' instance deleted "<<endl;
        }
};

class Driver : public Human{
    private:

        int license_number;
        string vehicle;

    public:
        Driver(const string & name, int age, int weight, int license, const string & vehicle){
            this->name = name;
            this->age = age;
            this->weight = weight;
            this->license_number = license;
            this->vehicle = vehicle;
        }

        void DisplayInfo(){
            cout<<"Driver name is : "<<name<<endl;
            cout<<"Age is : "<<age<<endl;
            cout<<"Licence number is : "<<license_number<<endl;
            cout<<"Vehicle is : "<<vehicle<<endl;

            cout<<"Thank You!!!!"<<endl;
        }

        ~Driver(){
            cout<<"Driver \'"<<name<<"\' instance deleted "<<endl;
        }
};


int main()
{
    Student s1("Ram", 15,40, 1, "Fifth");
    s1.Print();
    cout<<"=========================="<<endl;

    Teacher t1("Sattu",25, 60, 5, "English");
    t1.Print();
    cout<<"=========================="<<endl;

    Driver d1("Ram Babu", 35, 65, 1245789, "Scorpio");
    d1.DisplayInfo();
    cout<<"=========================="<<endl;
  return 0;
}