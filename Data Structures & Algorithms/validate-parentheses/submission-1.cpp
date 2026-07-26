class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.length(); i++) {
            char tp;
            if (st.empty())
                tp = '.';
            else
                tp = st.top();
            if (s[i] == '[' || s[i] == '(' || s[i] == '{') {
                st.push(s[i]);
            } else if ((tp == '(' && s[i] == ')') || (tp == '{' && s[i] == '}') ||
                       (tp == '[' && s[i] == ']')) {
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty();
    }
};
