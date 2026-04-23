class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> result(n, 0);

        unordered_map<int, vector<int>> mpp;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }

        for (auto& it : mpp) {
            vector<int>& ind = it.second;
            int m = ind.size();

            vector<long long> prefix(m + 1, 0);

            for (int i = 0; i < m; i++) {
                prefix[i + 1] = prefix[i] + ind[i];
            }

            for (int k = 0; k < m; k++) {
                long long left = (long long)k * ind[k] - prefix[k];
                long long right = (prefix[m] - prefix[k + 1]) -
                                  (long long)(m - k - 1) * ind[k];

                result[ind[k]] = left + right;
            }
            
        }
        return result;
    }
};