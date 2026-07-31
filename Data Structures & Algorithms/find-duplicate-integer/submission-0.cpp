class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map <int,int> m;
        for(int x:nums){
            m[x]++;
        }
        for(auto x:m){
            if(x.second>=2){
                return x.first;
            }
        }
        return 0;
    }
};
