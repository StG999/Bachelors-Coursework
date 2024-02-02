// "I have done this assignment on my own. I have not copied any code from another student or
// any online source. I understand if my code is found similar to somebody else's code, my case can
// be sent to the Disciplinary committee of the institute for appropriate action."

#include <iostream>
using namespace std;

void printingBrackets(int i, int j, int n, int *bracket, char &c)
{
    if (i == j)
    {
        cout << c++;
        return;
    }

    cout << "(";
    printingBrackets(i, *((bracket + i * n) + j), n, bracket, c);

    printingBrackets(*((bracket + i * n) + j) + 1, j, n, bracket, c);
    cout << ")";
}

void matrixChainMultiplication(int arr[], int n)
{

    int m[n][n];

    int bracket[n][n];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;

                    bracket[i][j] = k;
                }
            }
        }
    }

    char c = 'A';

    cout << "Optimal Parenthesization is : ";
    printingBrackets(1, n - 1, n, (int *)bracket, c);
    cout << endl;
    cout << m[1][n - 1] << " (Number of operations)";
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30, 10};
    int n = 6;
    matrixChainMultiplication(arr, n);
}