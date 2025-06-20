#include<iostream>
using namespace std;
/*
operator overloading - Redefine the behaviour of Operator . let's suppose + is mainly used to concatenate strings or adding of two numbers.
                       But + operator can't add two object of the same class , here is operator overloading used.
*/

// One of the classic example of operator overloading

class Complex{
    private:
        int real;
        int imaginary;

    public:
        Complex() : real(0), imaginary(0) {}

        Complex(int real, int img):real(real), imaginary(img){
            // this->real = real;
            // this->imaginary = img;
        }

        void Display(){
            cout<<"Complex number is : "<<real<<" + i"<<imaginary<<endl;
        }

        Complex operator +(Complex &c){ // c2 will be pass as argument.

            cout<<"Caller (this) object: "<<this->real<<" + i"<<this->imaginary<<endl;
            cout<<"Argument object: "<<c.real<<" + i"<<c.imaginary<<endl;
            cout<<"======================="<<endl;

            Complex temp; // temporary complex number.

            temp .real = real + c.real; // temp.real = this->real + c.real;
            temp.imaginary = imaginary + c.imaginary; // temp.imaginary = this->imaginary + c.imaginary; 

            return temp;
        }
};
int main()
{
    Complex c1(10,3); // caller
    // c1.Display();

    Complex c2(5,2); // argument
    // c2.Display();

    Complex c3 = c1 + c2; // without operator overloading addition can't be happen.
    //Complex c3 = c1.operator+(c2)

    c3.Display();
  return 0;
}