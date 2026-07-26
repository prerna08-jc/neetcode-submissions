class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        for(int i=0;i<9;i++){
            unordered_set<char> s;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(s.count(board[i][j])) return false;
                s.insert(board[i][j]);
            }
        }
        for(int i=0;i<9;i++){
            unordered_set<char> s;
            for(int j=0;j<9;j++){
                if(board[j][i]=='.') continue;
                if(s.count(board[j][i])) return false;
                s.insert(board[j][i]);
            }
        }
        for(int sq=0;sq<9;sq++){
            unordered_set<int> s;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    // important     // important
                    int r=(sq/3)*3+i; 
                    int c=(sq%3)*3+j;
                    if(board[r][c]=='.') continue;
                    if(s.count(board[r][c])) return false;
                    s.insert(board[r][c]);
                }
            }
        }
        return true;
    }
};


