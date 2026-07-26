class Solution {
   public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char, char> b = {{')', '('}, {'}', '{'}, {']', '['}};
        for (char c : s) {
            if (b.count(c)) {
                if (!st.empty() && st.top() == b[c]) {
                    st.pop();
                } else {
                    return 0;
                }
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
