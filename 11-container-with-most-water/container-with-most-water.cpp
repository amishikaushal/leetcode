class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int n = height.size();

        int r = n -1;


        int maxi = 0;


        while(l < r){
            int current = min(height[l] , height[r]) * (r-l );

            maxi = max(maxi , current);


            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxi;
    }
};