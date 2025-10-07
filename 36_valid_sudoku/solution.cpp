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

                string rowKey = "Number " + to_string(board[i][j]) + " found in row " + to_string(i);
                string colKey = "Number " + to_string(board[i][j]) + " found in column " + to_string(j);
                string boxKey = "Number " + to_string(board[i][j]) + " found in box " + to_string(i / 3) +
                                ", " + to_string(j / 3);

                if (elements.count(rowKey) == 1 ||
                    elements.count(colKey) == 1 ||
                    elements.count(boxKey) == 1)
                {
                    return false;
                }

                else
                {
                    elements.insert(rowKey);
                    elements.insert(colKey);
                    elements.insert(boxKey);
                }
            }
        }
        return true;
    };

    bool isValidSudokuOptimized(vector<vector<char>> &board)
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

                string rowKey = string(1, board[i][j]) + "r" + to_string(i);
                string colKey = string(1, board[i][j]) + "c" + to_string(j);
                string boxKey = string(1, board[i][j]) + "b" + to_string(i / 3) + to_string(j / 3);

                if (elements.count(rowKey) == 1 ||
                    elements.count(colKey) == 1 ||
                    elements.count(boxKey) == 1)
                {
                    return false;
                }

                else
                {
                    elements.insert(rowKey);
                    elements.insert(colKey);
                    elements.insert(boxKey);
                }
            }
        }
        return true;
    };

    bool isValidSudokuIntegerBased(vector<vector<char>> &board)
    {
        unordered_set<int> elements;
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }

                // convert the character digit (e.g., '5' -ascii 53-)
                // to its integer value (e.g., 5) by subtracting '0' -ascii 48-
                int val = board[i][j] - '0';
                // index boxes from 0 to 8 by starting each row index at 0, 3, 6 respectively and then adding the column index
                int boxIndex = (i / 3) * 3 + (j / 3);

                int rowKey = val * 1000 + 0 * 100 + i;
                int colKey = val * 1000 + 1 * 100 + j;
                int boxKey = val * 1000 + 2 * 100 + boxIndex;

                if (elements.count(rowKey) == 1 ||
                    elements.count(colKey) == 1 ||
                    elements.count(boxKey) == 1)
                {
                    return false;
                }

                elements.insert(rowKey);
                elements.insert(colKey);
                elements.insert(boxKey);
            }
        }
        return true;
    }
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
    cout << s.isValidSudokuOptimized(board) << endl;
    cout << s.isValidSudokuIntegerBased(board) << endl;

    return 0;
}