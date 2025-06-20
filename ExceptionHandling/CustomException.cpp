#include <iostream>
#include <exception>
using namespace std;

// Exception handling class
class InsufficientBalanceError : public runtime_error
{
    // protected:
    //     string messages;

public:
    InsufficientBalanceError(const string &msg) : runtime_error(msg)
    {
    }
};

class AccountNumberError : public runtime_error
{
public:
    AccountNumberError(const string &msg) : runtime_error(msg) {}
};

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
        if (amount <= 0)
        {
            throw InsufficientBalanceError("Deposit amount can't be negative ");
        }
        else
        {
            balance += amount;
            total_balance += amount;
            cout << "Money deposit to your bank. Now Total balance " << balance << endl;
        }
    }

    // withdraw
    void Withdraw(int amount)
    {
        if (amount <= 0)
        {
            throw InsufficientBalanceError("Withdrawal amount must be greater than zero");
        }
        if (amount > balance)
        {
            throw InsufficientBalanceError("Insufficient balance for withdrawal");
        }

        balance -= amount;
        total_balance -= amount;
        cout << "Money successfully withdrawn. Now total balance is " << balance << endl;
    }

    // check balance
    void CheckBalance()
    {
        cout << name << " , Your current Balance is : " << balance << endl;
    }

    void setAccNumber(int account_number)
    {
        if (account_number <= 0)
        {
            throw AccountNumberError("account number can't be negative ");
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
        cout << "Account " << account_number << " closed for " << name << endl;
    }
};

int Customer::total_account = 0;
int Customer::total_balance = 0;

int main()
{

    try
    {
        Customer c1("Ram", 1000, 1);
        c1.Deposit(0);
    }
    

    catch (const AccountNumberError &e)
    {
        cout << "Account Error: " << e.what() << endl;
    }
    catch (const InsufficientBalanceError &e)
    {
        cout << "Balance Error: " << e.what() << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "General Runtime Error: " << e.what() << endl;
    }

    // c1.DisplayDetails();
    // cout << "===========" << endl;

    return 0;
}