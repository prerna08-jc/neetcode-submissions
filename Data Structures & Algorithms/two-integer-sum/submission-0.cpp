class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> m; // Stores number -> its index
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int t = target - x;
            // Check if complement is ALREADY in our map
            if (m.find(t) != m.end()) {
                return {m[t], i}; // Found! Return stored index and current index
            }
            // Store current number with its index
            m[x] = i;
        }
        return {}; // Return empty vector if no solution
    }
};