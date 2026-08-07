class Solution {
public:
    vector<vector<string>> res;
    vector<bool> col;
    vector<bool> posDiag; // Index: r + c
    vector<bool> negDiag; // Index: r - c + (n - 1)

    vector<vector<string>> solveNQueens(int n) {
        col.resize(n, false);
        posDiag.resize(2 * n - 1, false);
        negDiag.resize(2 * n - 1, false);
        vector<string> board(n, string(n, '.'));

        backtrack(0, n, board);
        return res;
    }

private:
    void backtrack(int r, int n, vector<string>& board) {
        if (r == n) {
            res.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++) {
            int negIdx = r - c + (n - 1); // Offset by (n - 1) to prevent negative indices
            int posIdx = r + c;
            if (col[c] || posDiag[posIdx] || negDiag[negIdx]) {
                continue;
            }
            col[c] = true;
            posDiag[posIdx] = true;
            negDiag[negIdx] = true;
            board[r][c] = 'Q';
            
            backtrack(r + 1, n, board);
            col[c] = false;
            posDiag[posIdx] = false;
            negDiag[negIdx] = false;
            board[r][c] = '.';
        }
    }
};