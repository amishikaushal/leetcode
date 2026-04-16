class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int , vector<int>> mpp;

        for(int i = 0; i < n ; i++){
            mpp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for(auto &q : queries){
            vector<int> &v = mpp[nums[q]];

            if(v.size() == 1){
                ans.push_back(-1);
                continue;
            }

            int pos = lower_bound(v.begin() , v.end() , q) - v.begin();

            int res = INT_MAX;

             int left = v[(pos - 1 + v.size()) % v.size()];
            int d1 = abs(q - left);
            res = min(res, min(d1, n - d1));

       
            int right = v[(pos + 1) % v.size()];
            int d2 = abs(q - right);
            res = min(res, min(d2, n - d2));

            ans.push_back(res);







        }
        return ans;



        
    }
};