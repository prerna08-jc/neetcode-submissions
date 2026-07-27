class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temp[i] > temp[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                res[prevIndex] = i - prevIndex;
            }
            st.push(i);
        }
        return res;
    }
};
