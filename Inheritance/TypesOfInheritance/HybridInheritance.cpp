#include<iostream>
using namespace std;

/*
Hybrid Inheritance - Mix of Hierarchical and Multiple Inheritance.

1. `Boy` inherits from `Male` + `Student` => Multiple
2. `Girl` inherits from `Female` + `Student` => Multiple
3. `Student` is common base => Hierarchical applied with Male/Female → Student → Boy/Girl
*/

// -------- Parent class: Student --------
class Student {
protected:
    int rollNumber;
    string schoolName;

public:
    Student(int roll, string school) {
        this->rollNumber = roll;
        this->schoolName = school;
    }

    void DisplayStudent() {
        cout << "Roll Number : " << rollNumber << endl;
        cout << "School Name : " << schoolName << endl;
    }
};

// -------- Parent class: Male --------
class Male {
protected:
    string beardStyle;

public:
    Male(string beard) {
        this->beardStyle = beard;
    }

    void DisplayMale() {
        cout << "Beard Style : " << beardStyle << endl;
    }
};

// -------- Parent class: Female --------
class Female {
protected:
    bool longHair;

public:
    Female(bool hair) {
        this->longHair = hair;
    }

    void DisplayFemale() {
        if(longHair)
            cout << "Has Long Hair : Yes" << endl;
        else
            cout << "Has Long Hair : No" << endl;
    }
};

// -------- Child class: Boy (inherits from Male + Student) --------
class Boy : public Male, public Student {
private:
    string favSport;

public:
    Boy(string beard, int roll, string school, string sport) // this is modern way for constructor rather than using this
        : Male(beard), Student(roll, school), favSport(sport) {}

    void DisplayBoy() {
        cout << "----- Boy Profile -----" << endl;
        DisplayMale(); // display characteristic of male as a boy
        DisplayStudent(); // show property of student as a boy
        cout << "Favourite Sport : " << favSport << endl;
    }
};

// -------- Child class: Girl (inherits from Female + Student) --------
class Girl : public Female, public Student {
private:
    string favSubject;

public:
    Girl(bool hair, int roll, string school, string subject) // modern way to use constructor
        : Female(hair), Student(roll, school), favSubject(subject) {}

    void DisplayGirl() {
        cout << "----- Girl Profile -----" << endl;
        DisplayFemale(); // displa female behaviour as a girl
        DisplayStudent(); // display student behaviour as a girl student
        cout << "Favourite Subject : " << favSubject << endl;
    }
};

int main()
{
    // create Boy object
    Boy b1("Simple", 101, "IPS", "Cricket");
    b1.DisplayBoy();
    cout << "=======================" << endl;

    // create Girl object
    Girl g1(false, 102, "Apna School", "Mathematics");
    g1.DisplayGirl();

    return 0;
}
