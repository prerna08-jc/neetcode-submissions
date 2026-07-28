class Solution {
   public:
    int bsearch(vector<int>& nums, int l, int r, int target) {
        if (l > r) return -1;
        int mid = (l + (r - l) / 2);
        if (nums[mid] == target) {
            return mid;
        }
        return (nums[mid] < target) ? bsearch(nums, mid + 1, r, target)
                                    : bsearch(nums, l, mid - 1, target);
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = bsearch(nums, 0, n - 1, target);
        return ans;
    }
};
