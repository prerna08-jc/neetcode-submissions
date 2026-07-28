class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int thrs) {
        int h = 0;
        for (int i = 0; i < piles.size(); i++) {
            h = max(h, piles[i]);
        }
        int l = 1;
        while (h >= l) {
            int mid = l + (h - l) / 2;
            int hr = 0;
            for (int i = 0; i < piles.size(); i++) {
                hr += (piles[i] + mid - 1) / mid;  // this is done for calculating ceil division
            }
            if (hr <= thrs) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
