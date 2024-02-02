#include <iostream>
#include <fstream>

using namespace std;

class Employee
{
    public:
        
        string name;
        int ID;
        string dept;
        int salary;
        string address;
        long long contactNo;
        string emailID;
        string position;
        int experience;

        void printData()
        {
            cout<<name<<','<<ID<<','<<dept<<','<<salary<<','<<address<<','<<contactNo<<','<<emailID<<','<<position<<','<<experience<<endl;
            return;
        }
};

int main(void)
{
    // Employee e[50];
    Employee *e = new Employee[50];
    ifstream fin;
    fin.open("Lab1-2.txt");
    int i=0, counter=0;
    string ID, salary;
    string contactNo, experience;

    while(fin)
    {
        getline(fin, e[i].name, ' ');
        // getline(fin, s, ',);
        // e[i].name = s;

        getline(fin, ID, ' ');
        e[i].ID = stoi(ID);
        getline(fin, e[i].dept, ' ');
        getline(fin, salary, ' ');
        e[i].salary = stoi(salary);
        getline(fin, e[i].address, ' ');
        getline(fin, contactNo, ' ');
        e[i].contactNo = stoll(contactNo);
        getline(fin, e[i].emailID, ' ');
        getline(fin, e[i].position, ' ');
        getline(fin, experience, ' ');
        e[i].experience = stoi(experience);
        i++;
    }
    i--;

    int n;
    cout<<"Enter 0 to print counter values or 1 to run all questions: ";
    cin>>n;
    if(n == 0)
    {
        // CALCULATED VALUES OF COUNTER BY RUNNING THE PROGRAM ARE:
        cout<<"NOTE: The following table is created after running all questions in one go. I.e., the database is not resetted after each question.\nq1 - 00\nq2 - 00\nq3 - 00\nq4 - 00\nq5 - 28\nq6 - 25\nq7 - 00\nq8 - 28\nq9 - 28\n";
        return 0;
    }

    else if(n != 1)
    {
        cout<<"Error! Wrong value entered. Pls try again.\n";
        return 1;
    }

    // ANS FOR Q1 ---------------------------------------------------------------------------------------------------------------------------------
    int inputID;
    cin>>inputID;
    for(int k=0; k<i; k++)
        if(e[k].ID == inputID)
        {
            cout<<e[k].name<<endl;
            break;
        }
    cout<<"counter: "<<counter<<endl;
    // ANS FOR Q2 ---------------------------------------------------------------------------------------------------------------------------------
    counter = 0;
    e[0].printData();
    cout<<"counter: "<<counter<<endl;

    // ANS FOR Q3 ---------------------------------------------------------------------------------------------------------------------------------
    counter = 0;
    e[i-1].printData();
    cout<<"counter: "<<counter<<endl;

    // ANS FOR Q4 ---------------------------------------------------------------------------------------------------------------------------------
    counter = 0;
    i--;
    cout<<"counter: "<<counter<<endl;


    // ANS FOR Q5 ---------------------------------------------------------------------------------------------------------------------------------
    counter = 0;
    for(int k=0; k<i-1; k++)
    {
        e[k] = e[k+1];
        counter++;
    }
    i--;
    cout<<"counter: "<<counter<<endl;
    
    // ANS FOR Q6 ---------------------------------------------------------------------------------------------------------------------------------
    counter = 0;
    int position = 3;
    
    for(int k=position-1; k<i-1; k++)
    {
        e[k] = e[k+1];
        counter++;
    }
    i--;
    cout<<"counter: "<<counter<<endl;
    
    // ANS FOR Q7 ---------------------------------------------------------------------------------------------------------------------------------
    counter = 0;

    cin>>e[i].name;
    cin>>e[i].ID;
    cin>>e[i].dept;
    cin>>e[i].salary;
    cin>>e[i].address;
    cin>>e[i].contactNo;
    cin>>e[i].emailID;
    cin>>e[i].position;
    cin>>e[i].experience;

    i++;
    cout<<"counter: "<<counter<<endl;
    
    // ANS FOR Q8 ---------------------------------------------------------------------------------------------------------------------------------
    counter = 0;

    for(int k=i-1; k>=0; k--)
    {
        e[k+1] = e[k];
        counter++;
    }

    cin>>e[0].name;
    cin>>e[0].ID;
    cin>>e[0].dept;
    cin>>e[0].salary;
    cin>>e[0].address;
    cin>>e[0].contactNo;
    cin>>e[0].emailID;
    cin>>e[0].position;
    cin>>e[0].experience;
    cout<<"counter: "<<counter<<endl;
    i++;
    
    // ANS FOR Q9 ---------------------------------------------------------------------------------------------------------------------------------
    counter = 0, position = 2;

    for(int k=i-1; k>=position-1; k--)
    {
        e[k+1] = e[k];
        counter++;
    }
    i++;

    cin>>e[position-1].name;
    cin>>e[position-1].ID;
    cin>>e[position-1].dept;
    cin>>e[position-1].salary;
    cin>>e[position-1].address;
    cin>>e[position-1].contactNo;
    cin>>e[position-1].emailID;
    cin>>e[position-1].position;
    cin>>e[position-1].experience;
    cout<<"counter: "<<counter<<endl;
}