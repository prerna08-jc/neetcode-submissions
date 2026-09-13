class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;
        int maxLen = 1;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        int cnt=n;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                // For length 2, only need to check s[i] == s[j]
                // For length > 2, inner substring must also be palindrome
                if (s[i] == s[j] && (len == 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
