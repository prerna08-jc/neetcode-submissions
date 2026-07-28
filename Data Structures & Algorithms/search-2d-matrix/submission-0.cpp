class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = n - 1;
        int row = -1;
        while (l <= r) {
            int midRow = l + (r - l) / 2;
            if (matrix[midRow][0] > target) {
                r = midRow - 1;
            } else if (matrix[midRow][m - 1] < target) {
                l = midRow + 1;
            } else {
                row = midRow;
                break;
            }
        }
        if (row == -1) return false;
        int low = 0, high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[row][mid] == target) return true;
            if (matrix[row][mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};