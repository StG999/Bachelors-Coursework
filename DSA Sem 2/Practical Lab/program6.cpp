// 6. Write a program to store the marks obtained by 10 students in 5 courses in a two-dimensional array

#include <iostream>
using namespace std;

int main()
{
    int arr[5][10];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << "Enter the marks of course no. " << i + 1 << " by student no. " << j + 1 << " is : ";
            cin >> arr[i][j];
        }
        cout << endl;
    }

    return 0;
}