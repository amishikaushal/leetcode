class Solution {
public:
    bool isPossible(vector<int>& weights, int days , int cap){
        int d = 1;
        int load = 0;


        for(int i = 0; i < weights.size() ; i++){
            if(weights[i] + load > cap){
                d++;
                load = weights[i];
            }
            else{
                load += weights[i];
            }
        }
        return d <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin() , weights.end());
        int h = accumulate(weights.begin() , weights.end() , 0);

        int ans = h;

        while(l <= h){
            int mid = l + (h - l)/2;

            if(isPossible(weights , days , mid)){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};