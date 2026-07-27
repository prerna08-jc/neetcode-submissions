class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Second operand is popped first!
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();

                if (token == "+") st.push(op1 + op2);
                else if (token == "-") st.push(op1 - op2);
                else if (token == "*") st.push(op1 * op2);
                else if (token == "/") st.push(op1 / op2);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};