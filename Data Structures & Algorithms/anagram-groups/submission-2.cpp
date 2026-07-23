class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Fast I/O for competitive programming / LeetCode benchmarks
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<string, vector<string>> res;
        for (const string& s : strs) {
            // Fixed 26-character string filled with 0s
            string key(26, 0);             
            for (char c : s) {
                key[c - 'a']++;
            }           
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        result.reserve(res.size()); // Pre-allocate memory to avoid re-allocations        
        for (auto& pair : res) {
            result.push_back(move(pair.second)); // move() transfers ownership without copying
        }
        return result;
    }
};