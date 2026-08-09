class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        // using heap
        vector<int> count(26, 0);
        for (char c : tasks) {
            count[c - 'A']++;
        }
        priority_queue<int> mh;
        for (int c : count) {
            if (c > 0) {
                mh.push(c);
            }
        }
        int time = 0;
        queue<pair<int, int>> q;
        while (!mh.empty() || !q.empty()) {
            time++;
            if (mh.empty()) {
                time = q.front().second;
            } 
            else {
                int cnt = mh.top() - 1;
                mh.pop();
                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }
            if (!q.empty() && q.front().second == time) {
                mh.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
