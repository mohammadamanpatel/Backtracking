#include <iostream>
#include <vector>
using namespace std;
void printsolution(int n, vector<vector<char>> &board)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool isSafe(vector<vector<char>> &board, int col, int row, int n)
{
    int i = row;
    int j = col;
    // check in a left row
    while (j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        j--;
    }
    i = row;
    j = col;
    // check in left upper diagonal
    while (i >= 0 and j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j--;
    }
    // check in left lower diagonal
    i = row;
    j = col;
    while (i < n and j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i++;
        j--;
    }
    // ab agar saari conditions false aayi means queen place ho sakti hai to true return hoga .
    return true;
}
void solution(int n, vector<vector<char>> &board, int col)
{
    // base case
    if (col >= n)
    {
        printsolution(n, board);
        return;
    }
    // ek case
    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, col, row, n))
        {
            board[row][col] = 'Q';
            solution(n, board, col + 1);
            board[row][col] = '-';
        }
    }
}
int main()
{
    int n = 9;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    int col = 0;
    solution(n, board, col);
    return 0;
}
