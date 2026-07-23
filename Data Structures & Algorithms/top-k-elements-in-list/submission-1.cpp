class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> m;
        vector<vector<int>> freq(nums.size()+1);
        for(int n:nums){
            m[n]++;
        }
        for(auto x:m){
            freq[x.second].push_back(x.first);
        }
        vector<int> ans;
        for(int i=freq.size()-1;i>0;i--){
            for(int n:freq[i]){
                ans.push_back(n);
                if(ans.size()==k){
                    return ans;
                }
            }
        }
        return ans;
    }
};
