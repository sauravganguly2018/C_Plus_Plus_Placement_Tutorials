//*******************************************----Coded by Saurav Ganguly----*******************************************
#include <iostream>
using namespace std;

bool isSafe(int **arr, int n, int x, int y)
{
    int row = y - 1;
    int col = x;
    while (row >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
    }
    row = y - 1;
    col = x - 1;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }
    row = y - 1;
    col = x + 1;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nQueen(int **arr, int n, int y)
{
    if (y >= n)
    {
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(arr, n, i, y))
        {
            arr[y][i] = 1;
            if (nQueen(arr, n, y + 1))
            {
                return true;
            }
            arr[y][i] = 0;  //backtracking
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter the size of the matrix : ";
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    nQueen(arr, n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}