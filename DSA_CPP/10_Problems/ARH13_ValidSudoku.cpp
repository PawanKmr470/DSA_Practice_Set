#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// REF : https://leetcode.com/problems/valid-sudoku/description/
// NOTES :
//      ROW, COL, BOX indices
//      Box indices - rows 0,1,2 and cols 0,1,2
//      so made 9 strings "00", "01", "10", "11", "02", "20", "12", "21", "22" as box keys

// T: O(n) n = m*n
// S: O(n)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<string, unordered_set<char>> squares;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                
                if (board[r][c] == '.')
                    continue;

                string bIdx = to_string(r/3) + to_string(c/3);
                if (rows[r].find(board[r][c]) != rows[r].end() or \
                    cols[c].find(board[r][c]) != cols[c].end() or \
                    squares[bIdx].find(board[r][c]) != squares[bIdx].end()) {
                        return false;
                }

                rows[r].insert(board[r][c]);
                cols[c].insert(board[r][c]);
                string boxIndex = to_string(r/3) + to_string(c/3);
                squares[boxIndex].insert(board[r][c]);
            }
        }

        return true;
    }
};

// Using single hash set
// T: O(n) n = m*n
// S: O(n)
class Solution2 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> h;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                
                if (board[r][c] == '.')
                    continue;

                string row_str = "row" + to_string(r) + to_string(board[r][c]);
                string col_str = "col" + to_string(c) + to_string(board[r][c]);
                string box_str = "box" + to_string((r/3)*3 + (c/3)) + to_string(board[r][c]);

                if (h.find(row_str) != h.end() || \
                    h.find(col_str) != h.end() || \
                    h.find(box_str) != h.end()) {
                    return false;
                }

                h.insert(row_str);
                h.insert(col_str);
                h.insert(box_str);
            }
        }

        return true;
    }
};

int main() {
    return 0;
}