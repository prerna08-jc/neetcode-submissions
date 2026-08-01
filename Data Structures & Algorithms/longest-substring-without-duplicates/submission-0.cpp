class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int l = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            while (st.find(s[i]) != st.end()) {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[i]);
            res = max(res, i - l + 1);
        }
        return res;
    }
};
