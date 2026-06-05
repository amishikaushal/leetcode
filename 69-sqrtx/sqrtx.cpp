class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;

        int l = 1;
        int h = x;
        int ans = 0;

        while(l <= h){
            int mid = l + (h - l)/2;

            long long val = 1LL * mid * mid;

            if(val == x){
                return mid;
            }
            else if(val < x){
                ans = mid;
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return ans;
    }
};