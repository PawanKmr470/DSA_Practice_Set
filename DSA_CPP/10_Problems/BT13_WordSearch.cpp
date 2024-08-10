#include <iostream>
#include <vector>
using namespace std;

// REF : https://leetcode.com/problems/word-search/description/
// NOTES :
//      Backtrack
//      False conditions - boundary conditions, if visited, word doesn't match

// T: O(n*m*4^wordLen)
// S: O(wordLen)

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(0, i, j, rows, cols, visited, board, word))
                    return true;
            }
        }
        return false;
    }

    bool dfs(int index, int r, int c,
             int rows, int cols, vector<vector<bool>>& visited,
             vector<vector<char>>& board, string& word) {

        if (index == word.size())
            return true;

        if (r < 0 || c < 0 ||               // boundary condition
            r >= rows || c >= cols ||       // boundary condition
            visited[r][c] == true ||        // if the element is already visited then return false
            board[r][c] != word[index])     // if word's letter doesn't match with board's letter
            return false;

        visited[r][c] = true;

        bool ret;
        ret = (dfs(index+1, r+1, c, rows, cols, visited, board, word) ||    // right
               dfs(index+1, r, c+1, rows, cols, visited, board, word) ||    // down
               dfs(index+1, r-1, c, rows, cols, visited, board, word) ||    // left
               dfs(index+1, r, c-1, rows, cols, visited, board, word));     // up
        
        visited[r][c] = false;

        return ret;
    }
};