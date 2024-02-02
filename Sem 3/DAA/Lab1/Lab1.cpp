#include <iostream>
#include <string.h>

using namespace std;

typedef struct employee
{
    string Name;
    string ID;
    string Dept;
    string Salary;
    string Address;
    string Contact;
    string EmailID;
    string Position;
    string Experience;
}employee;

void fillData(employee *employees, int size)
{
    for (int i = 0; i < size; i++)
    {
        // employees[i].Name = getline(a, )
    }
}

// int main(void)
// {
    // employee employees[30];

// }

int main()
{
    char fname[1024];
    string arr[270];
    int i=0;
    employee employees[30];
    // printf("Enter the file name: ");
    // scanf ("%s", fname);

    FILE *file = fopen("D:/VSCode/NSUT/Sem 3/DAA/Lab1.csv", "r");

    if (!file)
    {
        printf("Could not open the file\n");
        return 0;
    }

    char content[1024];
    while (fgets(content, 1024, file))
    {
        char *v = strtok(content, ",");
        while (v)
        {
            // printf("%s ", v);
            arr[i] = v;
            v = strtok(NULL, ",");
            i++;
        }
        // printf("\n");
    }

    for(int i=0; i<270; i++)
        cout<<arr[i]<<" ";
    fclose(file);

    for(int i=0; i<270; i++)
    {
        if(i%9 == 0)
            employees[i%9].Name = arr[i];
        else if(i%9 == 1)
            employees[i%9].ID = arr[i];
        else if(i%9 == 2)
            employees[i%9].Dept = arr[i];
        else if(i%9 == 3)
            employees[i%9].Salary = arr[i];
        else if(i%9 == 4)
            employees[i%9].Address = arr[i];
        else if(i%9 == 5)
            employees[i%9].Contact = arr[i];
        else if(i%9 == 6)
            employees[i%9].EmailID = arr[i];
        else if(i%9 == 7)
            employees[i%9].Position = arr[i];
        else if(i%9 == 8)
            employees[i%9].Experience = arr[i];
    }

    cout<<"Name: "<<employees[0].Name<<endl;

    return 0;
}