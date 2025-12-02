// Given an m x n grid of characters board and a string word,
// return true if word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cells,
// where adjacent cells are horizontally or vertically neighboring.
// The same letter cell may not be used more than once.
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool dfs1(const vector<vector<char>> &board, const int i, const int j,
              const string &word, int targetIndex,
              vector<vector<bool>> &visited)
    {
        if (targetIndex == word.size())
            return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[targetIndex] || visited[i][j])
            return false;

        visited[i][j] = true;

        targetIndex += 1;
        bool found = (dfs1(board, i, j + 1, word, targetIndex, visited) ||
                      dfs1(board, i, j - 1, word, targetIndex, visited) ||
                      dfs1(board, i + 1, j, word, targetIndex, visited) ||
                      dfs1(board, i - 1, j, word, targetIndex, visited));

        visited[i][j] = false; // backtrack

        return found;
    }

    bool dfsImproved(vector<vector<char>> &board, const int i, const int j,
                     const string &word, int targetIndex)
    {
        if (targetIndex == word.size())
            return true;

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[targetIndex])
            return false;

        char tmp = board[i][j];
        board[i][j] = '#';

        targetIndex += 1;
        bool found = (dfsImproved(board, i, j + 1, word, targetIndex) ||
                      dfsImproved(board, i, j - 1, word, targetIndex) ||
                      dfsImproved(board, i + 1, j, word, targetIndex) ||
                      dfsImproved(board, i - 1, j, word, targetIndex));

        board[i][j] = tmp;
        return found;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int targetIndex = 0; // to know which letter of input word we are looking for next

        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (dfsImproved(board, i, j, word, targetIndex))
                    return true;
        return false;
    }
};

int main()
{
    string word = "ABCCEDS";
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    Solution s;
    bool ans = s.exist(board, word);
    ans == 1 ? cout << "word found" : cout << "word not found";
    cout << endl;

    return 0;
}
