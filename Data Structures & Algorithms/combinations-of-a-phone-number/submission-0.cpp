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
        if (curr.size() == digits.size()) {
            res.push_back(curr);
            return;
        }
        string chars = digitToChar[digits[i] - '0'];
        for (char c : chars) {
            backtrack(digits, curr + c, i + 1);
        }
    }
};
