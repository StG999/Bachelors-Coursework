#include <fstream>
#include <iostream>
using namespace std;
// DECLARATION OF STRUCTURE
struct EMPLOYEE{
 string NAME;
 string ID;
 string DEPARTMENT;
 string SALARY;
 string ADDRESS;
 string CONTACTNO;
 string EMAILID;
 string POSITION;
 string EXPERIENCE;
};

void PRINTEMPLOYEE(EMPLOYEE e)
{
    cout<<e.NAME<<" ";
    cout<<e.ID<<" ";
    cout<<e.DEPARTMENT<<" ";
    cout<<e.SALARY<<" ";
    cout<<e.ADDRESS<<" ";
    cout<<e.CONTACTNO<<" ";
    cout<<e.EMAILID<<" ";
    cout<<e.POSITION<<" ";
    cout<<e.EXPERIENCE<<" ";
}

//DECLARE AND ALLOCATE MEMORY
int main()
{
    struct EMPLOYEE arr[50];

    ifstream fin("file.csv");
    int n=0, counter=0;

    string s;

    while(fin)
    {
        getline(fin, s, ',');
        arr[n].NAME = s;
        getline(fin, s, ',');
        arr[n].ID = s;
        getline(fin, s, ',');
        arr[n].DEPARTMENT = s;
        getline(fin, s, ',');
        arr[n].SALARY = s;
        getline(fin, s, ',');
        arr[n].ADDRESS = s;
        getline(fin, s, ',');
        arr[n].CONTACTNO = s;
        getline(fin, s, ',');
        arr[n].EMAILID = s;
        getline(fin, s, ',');
        arr[n].POSITION = s;
        getline(fin, s, ',');
        arr[n].EXPERIENCE = s;
        n++;
    }
    // q1
    int id;
    cout<<"enter id";
    cin>>id;

    for(int i=0; i<n; i++)
    {
        if(stoi(arr[i].ID) == id)
            cout<<arr[i].NAME;
    }
    
    // q2
    PRINTEMPLOYEE(arr[0]);

    // q3
    PRINTEMPLOYEE(arr[n-1]);
}