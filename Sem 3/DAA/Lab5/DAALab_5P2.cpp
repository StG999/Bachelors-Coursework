// I have done this assignment on my own. I have not copied any code from
// another student or any online source. I understand if my code is found
// similar to somebody else's code, my case can be sent to the Disciplinary
// committee of the institute for appropriate action.

#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> mat, int row, int column)
{

    for (int i = 0; i < column; i++)
    {

        for (int j = 0; j < row; j++)
            cout << mat[i][j] << " ";

        cout << endl;
    }
    cout << endl;
    return;
}

void add_matrix(vector<vector<int>> matrix_A, vector<vector<int>> matrix_B, vector<vector<int>> &matrix_C, int div_num)
{
    for (auto i = 0; i < div_num; i++)
        for (auto j = 0; j < div_num; j++)
            matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
}

int exit()
{

    return {};
}

vector<vector<int>> multiply(vector<vector<int>> mat_A, vector<vector<int>> mat_B, int row_A, int row_B, int col_A, int col_B)
{
    if (col_A != row_B)
        exit();
    
    vector<int> result_mat_row(col_B, 0);
    vector<vector<int>> result_mat(row_A, result_mat_row);

    if (col_A == 1)
        result_mat[0][0] = mat_A[0][0] * mat_B[0][0];
    else
    {
        int div_num = col_A / 2;

        vector<int> row_vector(div_num, 0);
        vector<vector<int>> result_mat_00(div_num, row_vector);
        vector<vector<int>> result_mat_01(div_num, row_vector);
        vector<vector<int>> result_mat_10(div_num, row_vector);
        vector<vector<int>> result_mat_11(div_num, row_vector);

        vector<vector<int>> a00(div_num, row_vector);
        vector<vector<int>> a01(div_num, row_vector);
        vector<vector<int>> a10(div_num, row_vector);
        vector<vector<int>> a11(div_num, row_vector);
        vector<vector<int>> b00(div_num, row_vector);
        vector<vector<int>> b01(div_num, row_vector);
        vector<vector<int>> b10(div_num, row_vector);
        vector<vector<int>> b11(div_num, row_vector);

        for (auto i = 0; i < div_num; i++)
            for (auto j = 0; j < div_num; j++)
            {
                a00[i][j] = mat_A[i][j];
                a01[i][j] = mat_A[i][j + div_num];
                a10[i][j] = mat_A[div_num + i][j];
                a11[i][j] = mat_A[i + div_num][j + div_num];
                b00[i][j] = mat_B[i][j];
                b01[i][j] = mat_B[i][j + div_num];
                b10[i][j] = mat_B[div_num + i][j];
                b11[i][j] = mat_B[i + div_num][j + div_num];
            }

        add_matrix(multiply(a00, b00, row_A, row_B, col_A, col_B), multiply(a01, b10, row_A, row_B, col_A, col_B), result_mat_00, div_num);
        add_matrix(multiply(a00, b01, row_A, row_B, col_A, col_B), multiply(a01, b11, row_A, row_B, col_A, col_B), result_mat_01, div_num);
        add_matrix(multiply(a10, b00, row_A, row_B, col_A, col_B), multiply(a11, b10, row_A, row_B, col_A, col_B), result_mat_10, div_num);
        add_matrix(multiply(a10, b01, row_A, row_B, col_A, col_B), multiply(a11, b11, row_A, row_B, col_A, col_B), result_mat_11, div_num);

        for (auto i = 0; i < div_num; i++)
            for (auto j = 0; j < div_num; j++)
            {
                result_mat[i][j] = result_mat_00[i][j];
                result_mat[i][j + div_num] = result_mat_01[i][j];
                result_mat[div_num + i][j] = result_mat_10[i][j];
                result_mat[i + div_num][j + div_num] = result_mat_11[i][j];
            }

        result_mat_00.clear();
        result_mat_01.clear();
        result_mat_10.clear();
        result_mat_11.clear();
        a00.clear();
        a01.clear();
        a10.clear();
        a11.clear();
        b00.clear();
        b01.clear();
        b10.clear();
        b11.clear();
    }
    return result_mat;
}

int main()
{

    int row_A, row_B;
    int col_A, col_B;

    cin >> row_A >> col_A >> row_B >> col_B;

    vector<vector<int>> mat_A;
    vector<vector<int>> mat_B;

    for (int i = 0; i < col_A; i++)
    {
        vector<int> temp;

        for (int j = 0; j < row_A; j++)
        {
            int num;
            cin >> num;
            temp.push_back(num);
        }
        mat_A.push_back(temp);
    }

    for (int i = 0; i < col_B; i++)
    {
        vector<int> temp;

        for (int j = 0; j < row_B; j++)
        {
            int num;
            cin >> num;
            temp.push_back(num);
        }
        mat_B.push_back(temp);
    }

    cout << "Martix A" << endl;
    print(mat_A, row_A, col_A);

    cout << "Martix B" << endl;
    print(mat_B, row_B, col_B);

    vector<vector<int>> answer(multiply(mat_A, mat_B, row_A, col_A, row_B, col_B));

    cout << "Multiply " << endl;
    print(answer, row_A, col_B);
}