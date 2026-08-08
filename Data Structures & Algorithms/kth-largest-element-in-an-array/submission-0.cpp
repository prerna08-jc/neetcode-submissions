class Solution {
public:
priority_queue<int,vector<int>,greater<int>> p;
    int findKthLargest(vector<int>& nums, int k) {
        for(int num:nums){
            p.push(num);
            if(p.size()>k){
                p.pop();
            }
        }
        return p.top();
    }
};
