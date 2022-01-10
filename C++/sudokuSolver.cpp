#include <bits/stdc++.h>
using namespace std;
#define ll long long
static const int GRID_SIZE = 9;

void printBoard(int board[9][9])
{
    for (int row = 0; row < GRID_SIZE; row = row + 1)
    {
        if (row % 3 == 0 && row != 0)
        {
            cout << "----------------------\n";
        }
        for (int column = 0; column < GRID_SIZE; column = column + 1)
        {
            if (column % 3 == 0 && column != 0)
            {
                cout << "|";
            }
            cout << " " << board[row][column];
        }
        cout << endl;
    }
}

bool isNumberInRow(int board[9][9], int number, int row)
{
    for (int i = 0; i < GRID_SIZE; i = i + 1)
    {
        if (board[row][i] == number)
        {
            return true;
        }
    }
    return false;
}

bool isNumberInColumn(int board[9][9], int number, int column)
{
    for (int i = 0; i < GRID_SIZE; i = i + 1)
    {
        if (board[i][column] == number)
        {
            return true;
        }
    }
    return false;
}

bool isNumberInBox(int board[9][9], int number, int row, int column)
{
    int localBoxRow = row - row % 3;
    int localBoxColumn = column - column % 3;

    for (int i = localBoxRow; i < localBoxRow + 3; i = i + 1)
    {
        for (int j = localBoxColumn; j < localBoxColumn + 3; j = j + 1)
        {
            if (board[i][j] == number)
            {
                return true;
            }
        }
    }
    return false;
}

bool isValidPlacement(int board[9][9], int number, int row, int column)
{
    return !isNumberInRow(board, number, row) &&
           !isNumberInColumn(board, number, column) &&
           !isNumberInBox(board, number, row, column);
}

bool solveBoard(int board[9][9])
{
    for (int row = 0; row < GRID_SIZE; row = row + 1)
    {
        for (int column = 0; column < GRID_SIZE; column = column + 1)
        {
            if (board[row][column] == 0)
            {
                // from 1 to 9
                for (int numberToTry = 1; numberToTry <= GRID_SIZE; numberToTry = numberToTry + 1)
                {
                    if (isValidPlacement(board, numberToTry, row, column))
                    {
                        board[row][column] = numberToTry;
                        if (solveBoard(board))
                        {
                            return true;
                        }
                        else
                        {
                            board[row][column] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(void)
{
    /*
     *variables that would be used in future implementation
     int n;
     cout << "Enter with the board dimensions";
     cin >> n;
     const int BOARD_SIZE = n;*/

    int board[9][9] = {
        {8, 0, 0, 0, 9, 3, 0, 0, 1},
        {0, 0, 0, 2, 0, 0, 0, 0, 0},
        {0, 5, 0, 0, 0, 0, 0, 6, 0},
        {9, 0, 0, 0, 1, 7, 0, 0, 3},
        {0, 0, 0, 0, 4, 0, 0, 0, 0},
        {0, 0, 8, 0, 0, 0, 9, 0, 0},
        {7, 0, 0, 4, 0, 0, 0, 0, 0},
        {0, 0, 6, 0, 7, 2, 0, 1, 0},
        {0, 0, 0, 8, 0, 0, 0, 0, 2}};

    printBoard(board);

    if (solveBoard(board))
    {
        cout << "Solved successfully\n";
    }
    else
    {
        cout << "Unsolvable board :(\n";
    }
    printBoard(board);
    return (0);
}