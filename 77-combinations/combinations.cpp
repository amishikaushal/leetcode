class Solution {
public:
    void solve(int start , int n , int k , vector<vector<int>> &ans , vector<int> &res){
        if(res.size() == k){
            ans.push_back(res);
            return;
        }

        if(start > n) return;

        res.push_back(start);

        solve(start +1 , n , k , ans , res);

        res.pop_back();
        solve(start +1 , n , k , ans , res);




    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> res;

        solve(1 , n , k , ans , res);

        return ans;
    }
};