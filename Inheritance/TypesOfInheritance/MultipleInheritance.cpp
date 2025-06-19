#include <iostream>
using namespace std;
/*
    Multiple Inheritance- Inherit property from more tha one class.
*/
class Coder
{
protected:
    string nameOfCoder;
    string codingLanguage;
    int yearsOfExp;

public:
    Coder(const string &nameOfCoder, const string &name, int yearsOfExp)
    {
        this->nameOfCoder = nameOfCoder;
        this->codingLanguage = name;
        this->yearsOfExp = yearsOfExp;
    }

    void Display()
    {
        cout << "Display method of Coding class . " << endl;
    }

    ~Coder()
    {
        cout << "Destructor of Coding class " << codingLanguage << endl;
    }
};

class Gamer
{
protected:
    string nameOfGame;

public:
    Gamer(const string &nameOfGame)
    {
        this->nameOfGame = nameOfGame;
    }

    void Display()
    {
        cout << "Display method of Gamer class . " << endl;
    }

    ~Gamer()
    {
        cout << "Destructor of Gamer class "<<nameOfGame  << endl;
    }
};

// as we inherit number matter. like if coder , gamer then coder constructor execute first then gamer.
class Engineer : public Coder, Gamer
{
private:
    char favCharacter;

public:
    Engineer(const string &coderName, const string &codingLanguage, const string &gameName, int exp, char favChar) : Coder(coderName, codingLanguage, exp), Gamer(gameName), favCharacter(favChar)
    {
        // this->nameOfCoder = coderName;
        // this->codingLanguage = codingLanguage;
        // this->yearsOfExp = exp;
        // this->nameOfGame = gameName;
        // this-> = favChar;
    }

    void Display()
    { // if display is not define here then parent display method will called.

        cout << "Coder Name is : " << nameOfCoder << endl;
        cout << "Coding Language is : " << codingLanguage << endl;
        cout << "Year of Experience in this language : " << yearsOfExp << endl;
        cout<<"Game I like is : "<<nameOfGame<<endl;
        cout<<"My Favourite character is : "<<favCharacter<<endl;
    }

    ~Engineer(){
        cout<<"Destructor of enggg class "<<endl;
    }
};

int main()
{
    Engineer e1("Satyendra Gautam", "C++", "Ludo", 1, 'S');
    e1.Display();
    cout<<"====================="<<endl;
    return 0;
}