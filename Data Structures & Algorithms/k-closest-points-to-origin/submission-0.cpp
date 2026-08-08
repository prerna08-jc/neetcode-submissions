class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> h;  // distance, point(x,y)
        for (auto& pt : points) {
            int dist = pt[0] * pt[0] + pt[1] * pt[1]; // dist= x^2+y^2
            h.push({dist, pt});
            if (h.size() > k) {
                h.pop();
            }
        }
        vector<vector<int>> res;
        while (!h.empty()) {
            res.push_back(h.top().second);
            h.pop();
        }
        return res;
    }
};
