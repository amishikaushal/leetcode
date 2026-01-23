class Solution {
public:
    void solve(int ind , int k, int n , vector<int> res , vector<vector<int>> &ans){
        if(k == 0 && n == 0){
            ans.push_back(res);
            return;
        }

        if(ind > 9 || k < 0 || n < 0) return;


        res.push_back(ind);
        solve(ind + 1 , k - 1 , n - ind , res , ans);

        res.pop_back();
        solve(ind + 1 , k , n , res , ans);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> res;

        solve(1 , k , n , res , ans);
        return ans;
    }
};