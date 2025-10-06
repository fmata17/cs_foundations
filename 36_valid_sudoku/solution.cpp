#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;

// Determine if a 9 x 9 Sudoku board is valid.
// Only the filled cells need to be validated according to the following rules:
//
// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
//
// Note:
// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<string> elements;
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }

                if (elements.count("Number " + to_string(board[i][j]) + " found in row " + to_string(i)) == 1 ||
                    elements.count("Number " + to_string(board[i][j]) + " found in column " + to_string(j)) == 1 ||
                    elements.count("Number " + to_string(board[i][j]) + " found in box " + to_string(i / 3) +
                                   ", " + to_string(j / 3)) == 1)
                {
                    return false;
                }

                else
                {
                    elements.insert("Number " + to_string(board[i][j]) + " found in row " + to_string(i));
                    elements.insert("Number " + to_string(board[i][j]) + " found in column " + to_string(j));
                    elements.insert("Number " + to_string(board[i][j]) + " found in box " + to_string(i / 3) +
                                    ", " + to_string(j / 3));
                }
            }
        }
        return true;
    };
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> board =
        {{'1', '2', '.', '.', '3', '.', '.', '.', '.'},
         {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '.', '3'},
         {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
         {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    Solution s;
    cout << s.isValidSudoku(board) << endl;

    return 0;
}