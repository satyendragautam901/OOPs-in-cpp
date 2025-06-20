#include<iostream>
#include<vector>
using namespace std;
/*
Function Overriding - Define the same function in child class with same name. same function name , same return type and same arguments

*/

class Animal{
    public:
        virtual void  Speak(){ // Without `virtual`, this will not behave as runtime polymorphism (it'll be early binding) . But now behave like late binding.
 
            cout<<"Animal Speaking ."<<endl;
        }

        virtual ~Animal(){
            cout<<"Animal Destructor "<<endl;
        }
};

class Dogs : public Animal{
    public:
        // `override` is optional, but it's best practice. 
        // It ensures you're actually overriding a base class virtual function.

        void Speak () override {
            cout<<"Bhou Bho Bhoooooo"<<endl;
        }
};

class Lion : public Animal{
    public:
        void Speak() override{
            cout<<"Roarrrrrrrr"<<endl;
        }
};

class Cat : public Animal{
    public:
        void Speak() override{
            cout<<"Meou. Meou. "<<endl;
        }
};

int main()
{
    // Dogs GermanShapherd;
    // GermanShapherd.Speak();

    // Lion l1;
    // l1.Speak();

    /*
    if we use virtual in animal function then it will be function overriding . 
    with virtual it will execute at run time(late binding) , but if we don't use virtual then at compile time(early binding).
    It get executed and Animal speak() function will be called.
    */
    Animal *a1 = new Dogs; // this is also called Base class pointer and derive class object.
    a1->Speak(); // Bark

    Animal *a2 = new Animal;
    a2->Speak(); // animal speaking

    Animal *a3 = new Lion; // at run time it will decide that which animal speak to call.
    a3->Speak(); // roar 
    
    a3 = new Dogs; // thats why this way is easy as compared to Dogs d1.
    a3->Speak();
    cout<<"======================"<<endl;

    vector<Animal *>zoo; // let's suppose we are in zoo.
    zoo.push_back(new Cat);
    zoo.push_back(new Dogs);
    zoo.push_back(new Lion);

    for(auto a: zoo){
        a->Speak();
    }

    cout<<"======================"<<endl;

    delete a1;
    delete a2;
    delete a3;

  return 0;
}