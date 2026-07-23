class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map <int,int> m;
        for(int x:nums){
            m[x]++;
        }
        for(auto t:m){
            if(t.second>1){
                return true;
            }
        }
        return false;
    }
};