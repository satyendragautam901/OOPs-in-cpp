#include <iostream>
using namespace std;
class Customer
{
private:
    string name;
    int balance;
    int account_number;
    static int total_balance;
    static int total_account; // static data member
public:
    // constructor
    Customer(string name, int balance, int account_number)
    {

        setName(name);
        setBalance(balance);
        setAccNumber(account_number);
        total_account++;
    }

    // static member function
    static void AccessTotalAccount()
    {
        // this function can't access non-static data types
        cout << "Total account " << total_account << endl;
        cout << "Total balance in Bank " << total_balance << endl;
    }

    void setName(string name)
    {
        if (name == "")
        {
            cout << "Name can't be empty " << endl;
            return;
        }
        this->name = name;
    }
    void setBalance(int balance)
    {
        if (balance < 0)
        {
            cout << "Balance can't be negative " << endl;
            return;
        }
        else
        {
            this->balance = balance;
            total_balance += balance;
        }
    }

    // deposit balance
    void Deposit(int amount)
    {
        if (amount > 0)
        {
            balance += amount;
            total_balance += amount;
            cout << "Money deposit to your bank. Now Total balance " << balance << endl;
        }
    }

    // withdraw
    void Withdraw(int amount)
    {
        if (amount <= balance && amount > 0)
        {
            balance -= amount;
            total_balance -= amount;
            cout << "Money successfully withdraw from your bank. Now total balance is " << balance << endl;
        }
        else
        {

            cout << "Please enter amount less than your current balance. Your current balance is: " << balance << endl;
            return;
        }
    }

    // check balance
    void CheckBalance()
    {
        cout << name << " , Your current Balance is : " << balance << endl;
    }

    void setAccNumber(int account_number)
    {
        if (account_number < 0)
        {
            cout << "account number can't be negative " << endl;
            return;
        }
        this->account_number = account_number;
    }

    void Display_TotalCustomer()
    {
        cout << "total account " << total_account << endl;
    }

    void DisplayDetails() const
    {
        cout << "Customer Name: " << name << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Current Balance: " << balance << endl;
    }

    // destructor
    ~Customer()
    {
        // cout << "Account " << account_number << " closed for " << name << endl;
    }
};
// now this is static member . this variable will share across all the objects.
// this is member of class not object so it can accessible without object
int Customer::total_account = 0;
int Customer::total_balance = 0;

int main()
{
    // int total_account = 0; // if we declare variable to count number of account then can't work
    Customer c1("Ram", 1000, 1);
    c1.Deposit(1500);
    c1.DisplayDetails();
    cout<<"==========="<<endl;

    Customer c2("Shyam", 2000, 2);
    c2.CheckBalance();

    Customer c3("Ramu", 500, 3);

    Customer c4("Shyamu", 4000, 4);
    c4.CheckBalance();

    Customer::AccessTotalAccount(); // member function can be accessible without object

    return 0;
}