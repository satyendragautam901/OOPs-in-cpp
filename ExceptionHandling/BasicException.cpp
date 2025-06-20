#include<iostream>
#include<exception>
using namespace std;

// may be exception class looks like. This is not actual it's type i have create by own.
class Exception{
    protected:
        string messages;

    public:

    Exception(const string &msg): messages(msg){

    }

    string what(){
        return messages;
    }
};

class RuntimeError : public Exception{
    public:
        RuntimeError(const string &msg) : Exception(msg){}
};


int main()
{
    cout<<"Calculate the division of two numbers ."<<endl;
    float a, b;
    cout<<"Enter both numbers sequentially "<<endl;
    cin>>a>>b;
    
    /*
    
    if(b ==0){ // this way we can handle error too , but this is not right way.
        cout<<"Error during division "<<endl;
        return 0;
        }
        float c = a/b; // if b == 0 then it evaluate wrong.
    */

    try{
        if(b ==0){
            throw "Error during division ";
        }
        float c = a/b;
        cout<<"The division of a and b is : "<<c<<endl;
    }

    catch(const char *e){
        cout<<e<<endl;
    }

    // we can use runtime_error which is child class of exception class for this .
    
    int firstNumber = 1;
    int secondNumber = 0;
    try{
        if(secondNumber == 0){
            throw runtime_error("Base can't be zero ");
        }
        int c = firstNumber / secondNumber;
        cout<<"The result is : "<<float(c)<<endl;
    }

    catch(const runtime_error &e){
        cout<<"Error occured "<<e.what()<<endl;
    }

    
  return 0;
}