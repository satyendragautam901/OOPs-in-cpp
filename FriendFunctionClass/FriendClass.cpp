#include <iostream>
using namespace std;
/*
Friend class- A class have right to access all private/protected members and methods of the class.
*/

class Human
{
private:
    int age;

public:
    void secret()
    {
        cout << "This is a secret function!. in Base class" << endl;
    }
    friend class Me; // this is friend class.
};

class Me
{
public:
    void DisplayAge(Human &ram)
    {
        ram.age = 15;
        ram.secret();
        cout << "My age is " << ram.age << endl;
    }
};
int main()
{
    // Note   <------ But Human cannot access private members of Me, unless Me also makes Human a friend. -------->

    Human h1; // object of base class

    Me sattu; // object of derive class
    sattu.DisplayAge(h1);

    return 0;
}