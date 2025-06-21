#include<iostream>
using namespace std;
/*
Friend Function - Allows a non-member function to access the variable out side of class even the variable is private / protected.
*/
class Customer{
    private:
        string name;
        int balance;

    public:
        Customer(const string &name, int balance):name(name), balance(balance){  }

        // friend void SeeBalance(Customer c); // this is friend function. Here copy constructor is called so destructor will also called.
        friend void SeeBalance(Customer &c);
        /*
        Real life scenario - I told my friend to take my credit card and check balance.
    
        */

        ~Customer(){
            cout<<"Destructor "<<name<<endl;
        }
};

void SeeBalance(Customer &A){
    cout<<"The Balance is "<<A.balance<<endl;
}

int main()
{   
    Customer c("Ramu",5000);
    Customer d("Shyamu", 1000);
    SeeBalance(c);
    SeeBalance(d);
    return 0;
}