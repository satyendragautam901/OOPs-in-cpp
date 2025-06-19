#include <iostream>
using namespace std;
/*
    This is Diamond Inheritance

        Human
       /   \
   Coder  Gamer   ← virtual inheritance to avoid ambiguity
       \   /
      Engineer

*/

class Human
{
protected:
    string name;

public:
    Human()
    {
        cout << "Default Human Constructor called" << endl;
    }

    Human(const string &name)
    {
        this->name = name;
    }

    ~Human()
    {
        cout << "Destructor of Human " << endl;
    }
};

class Coder : virtual protected Human // virtual is neccessary to avoid multiple copy of Human class's variable
{
protected:
    string codingLanguage;

public:
    Coder(const string &codingLanguage, string name) : Human(name), codingLanguage(codingLanguage)
    {
        // this->codingLanguage = codingLanguage;
    }

    ~Coder()
    {
        cout << "Destructor of Coding class " << codingLanguage << endl;
    }
};

class Gamer : virtual protected Human
{
protected:
    string nameOfGame;

public:
    Gamer(const string &nameOfGame, string name) : Human(name), nameOfGame(nameOfGame)
    {
        // this->nameOfGame = nameOfGame;
    }

    ~Gamer()
    {
        cout << "Destructor of Gamer class " << nameOfGame << endl;
    }
};

// Engineer class inherits both Coder and Gamer — classic Diamond inheritance

class Engineer : public Coder, Gamer
{
private:
    int numberOfExp;

public:
    Engineer(const string &name, const string &codingLanguage, const string &nameOfGame, int numberOfExp) : Coder(codingLanguage, name), Gamer(nameOfGame, name), Human(name), numberOfExp(numberOfExp)
    {
    }
    void Display()
    {
        cout << "Name is : " << name << endl;
        cout << "Coding language is : " << codingLanguage << endl;
        cout << "Game I like is " << nameOfGame << endl;
        cout << "I have \'" << numberOfExp << "\' years experience in IT industry " << endl;
    }
    ~Engineer()
    {
        cout << "Destructor of Engineer " << endl;
    }
};
int main()
{
    Engineer e1("Gautam", "C++", "Cricket", 1);
    e1.Display();
    cout << "===========================" << endl;
    return 0;
}