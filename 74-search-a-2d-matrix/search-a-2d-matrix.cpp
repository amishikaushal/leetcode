class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int l = 0;
        int h = row * col - 1;

        while(l <= h){
            int mid = l + (h - l)/2;

            int ele = matrix[mid /col ][mid % col];

            if(ele < target){
                l = mid + 1;
            }
            else if(ele > target){
                h = mid -1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};