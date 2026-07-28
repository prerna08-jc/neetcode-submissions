class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<m;i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        double mid;
        if(nums1.size()%2==1){
            mid=nums1[(nums1.size()/2)];
        }
        else{
            mid=nums1[(nums1.size()/2)-1]+nums1[(nums1.size()/2)];
            mid=mid/2;
        }
        return mid;
    }
};
