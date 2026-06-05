class Solution {
public:
    long long hrs(vector<int> &nums , int speed){
        int n = nums.size();
        long long ans = 0;

        for(int i = 0; i < n ; i++){
            ans += (nums[i] + speed - 1)/ speed;
        }

        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin() , piles.end());


        while(low <= high){
            int mid = low + (high - low)/2;

            long long val = hrs(piles , mid);

            if(val <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};