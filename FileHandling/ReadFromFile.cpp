#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream file;
    file.open("work.text"); // open file to read

    if (file.is_open())
    {
        cout << "file open to read " << endl;

        /*
        char c = file.get();
        while (!file.eof())
        {
            cout<<c; // this way everything will be printed in single line.
            c = file.get();
        }
        */
        string text;
        while (getline(file, text)) // mostly print in new line
        {
            
            cout << text <<endl;
        }
    }
    file.close(); // close file after read

    return 0;
}