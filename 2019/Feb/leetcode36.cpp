class Solution {
public:
    inline int getidx(int x, int y) {
        return (x / 3) + (y / 3) * 3;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ok[15][15] = {0};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    if (ok[i][board[i][j] - '0'])
                        return false;
                    ok[i][board[i][j] - '0'] = 1;
                }
        }
        memset(ok, 0, sizeof(ok));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    if (ok[j][board[i][j] - '0'])
                        return false;
                    ok[j][board[i][j] - '0'] = 1;
                }
        }
        memset(ok, 0, sizeof(ok);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    if (ok[getidx(i, j)][board[i][j] - '0'])
                        return false;
                    ok[getidx(i, j)][board[i][j] - '0'] = 1;
                }
        }
        return true;
    }
};
