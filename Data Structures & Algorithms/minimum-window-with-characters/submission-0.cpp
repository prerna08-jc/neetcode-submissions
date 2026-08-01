class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return "";
        int hash[256] = {0};
        int l = 0, r = 0;
        int minLen = INT_MAX; 
        int sIndex = -1;  
        int cnt = 0;      
        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }
        while (r < n) {
            // If character is part of target t (count > 0), increment matched count
            if (hash[s[r]] > 0) {
                cnt = cnt + 1;
            }
            // Decrement frequency in hash
            hash[s[r]]--;
            // When all characters of t are present in current window [l..r]
            while (cnt == m) {
                // Update minimum length and starting index
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sIndex = l;
                }
                // Shrink window from the left
                hash[s[l]]++; //restoring the count as it is not a part of the window anymore
                // If s[l] was a required character, losing it decreases cnt
                if (hash[s[l]] > 0) {
                    cnt = cnt - 1;
                }
                l++;
            }
            r++; // Move right pointer
        }
        // Return empty string if no valid window found
        return sIndex == -1 ? "" : s.substr(sIndex, minLen);
    }
};