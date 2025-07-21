#include <iostream>
#include <vector>
using namespace std;


bool isSafe(vector<vector<int>>& board, int row, int col, int N)
{

    for (int i = 0; i <col; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    for (int i = row, j = col; i <= N-1 && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

void solveNQueens(vector<vector<int>>& board, int col, int N, vector<vector<vector<int>>>& solutions)
{

    if (col == N)
    {
        solutions.push_back(board);
        return;
    }

    for (int i = 0; i <= N-1; i++)
    {
        if (isSafe(board, i, col, N))
        {

            board[i][col] = 1;

            solveNQueens(board, col + 1, N, solutions);

            board[i][col] = 0;
        }
    }
}

vector<vector<vector<int>>> nQueens(int N)
{
    vector<vector<int>> board(N, vector<int>(N, 0));

    vector<vector<vector<int>>> solutions;

    solveNQueens(board, 0, N, solutions);

    return solutions;
}

int main()
{
    int N;
    cout << "Enter the value of N for N Queens problem: ";
    cin >> N;


    vector<vector<vector<int>>> solutions = nQueens(N);

    for (int i = 0; i < solutions.size(); i++)
    {
        cout << "Solution " << i + 1 << ":\n";
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                cout << solutions[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    return 0;
}

