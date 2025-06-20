#include<iostream>
using namespace std;
/*
Polymorphism -  many forms.
                A Selector in Paint application behave like many forms, like if we select to write, it behaves like it.
                If we select for erase then it behave like eraser etc...
*/

class Area{

    public:
        // circle area
        void CalculateArea(float radious){
            cout<<"Area of circle is "<<3.172 * radious *radious<<endl;
        }

        // area of Rectangle
         void CalculateArea(int length, int breadth){
            cout<<"Area of Rectangle is "<<(length * breadth)<<endl;
        }
        
};

class Man{
    /*
    A man have many forms like husband, engg, son, etc.
    */
    public:
        void Behaviour(){
            cout<<"Behave like Husband, Father, Son, Brother etc. "<<endl;
        }

        void Behaviour(string InOffice){
            cout<<"Behave like Developer, Engineer, Manager etc. "<<endl;
        }

        void Behaviour(char Custumer){
            cout<<"Behave like Customer, Normal Man etc. "<<endl;
        }
};

int main()
{
    Area circle;
    circle.CalculateArea(3.0);

    Area Rectangle;
    Rectangle.CalculateArea(4,7);

    Man m1;
    m1.Behaviour();
    m1.Behaviour("Engg");
    m1.Behaviour('c');
  return 0;
}