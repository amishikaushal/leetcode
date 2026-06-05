class Solution {
public:
    int dayreq(vector<int> &nums, int wt){
        int days = 1;

        int load = 0;
        int n = nums.size();

        for(int i = 0; i < n ; i++){
            if(load + nums[i] > wt){
                days += 1;
                load = nums[i];
            }
            else{
                load += nums[i];
            }
        }

        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int high = accumulate(weights.begin() , weights.end() , 0);

        int low = *max_element(weights.begin() , weights.end());
        //int ans = -1;

        while(low <= high){
            int mid = high + (low - high)/2;

            int day = dayreq(weights , mid);

            if(day <= days){
                //ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};