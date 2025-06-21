#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
int main()
{
    ofstream file; // this is for open and write something to file.
    file.open("work.text"); // if file is not found then first create then open.
    file<<"Hello Ji kaise ho \n";
    file<<"I am software developer\n";
    file<<"Greetings!. From satyendra gautam \n"; // << this operator is used to insert into open file.

    // write user input number to file
    vector<int>arr(5);
    cout<<"Enter number "<<endl;
    for(int i = 0; i<5; i++){
      cin>>arr[i];
    }

    file<<"\n Unsorted data \n";
    for(int i = 0; i<5; i++){
      file<<arr[i]<<" ";
    }

    file<<"\n Sorted data \n";
    sort(arr.begin(), arr.end());

    for(int i = 0; i<5; i++){
      file<<arr[i]<<" ";
    }

    file.close(); // this will close open file 

    
   
    

  return 0;
}