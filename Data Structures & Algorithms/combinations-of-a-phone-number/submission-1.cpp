class Solution {
   public:
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return res;
        }
        backtrack(digits, "", 0);
        return res;
    }
    void backtrack(string digits, string curr, int i) {
        if (i == digits.size()) {
            res.push_back(curr);
            return;
        }
        int x = digits[i] - '0';
        for (int j = 0; j < digitToChar[x].size(); j++) {
            curr += digitToChar[x][j];
            backtrack(digits, curr, i + 1);
            curr.pop_back();
        }
    }
};
