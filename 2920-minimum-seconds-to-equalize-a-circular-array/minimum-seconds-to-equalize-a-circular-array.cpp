class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , vector<int>> mpp;


        for(int i = 0 ; i < n ; i++){
            mpp[nums[i]].push_back(i);
        }

        int result = INT_MAX;

        for(auto &[nums , pos] : mpp){
            int m = pos.size();

            int maxi = 0;

            for(int i = 0 ; i < m ; i++){
                int next = (i + 1) % m;
                int gap = (pos[next] - pos[i] - 1 + n) % n;
                maxi = max(maxi, gap);
            }

            int time = (maxi + 1) / 2;
            result = min(result, time);
        }

        return result;
    }
};