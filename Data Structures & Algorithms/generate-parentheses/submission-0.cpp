class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        backtrack(n, curr, res, 0, 0);
        return res;
    }
    void backtrack(int n, string& curr, vector<string>& res, int open, int close) {
        if (open == n && close == n) {
            res.push_back(curr);
            return;
        }
        if (open < n) {
            curr += "(";
            backtrack(n, curr, res, open + 1, close);
            curr.pop_back();
        }
        if (close < open) {
            curr += ")";
            backtrack(n, curr, res, open, close + 1);
            curr.pop_back();
        }
    }
};
