class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int mod = 12345;


   

        vector<vector<int>> ans(n , vector<int>(m , 1));
       
        long long prefix = 1;
        for(int i = 0 ; i < n * m ; i++){
            int r = i / m;
            int c = i % m ;


            ans[r][c] = prefix;
            prefix = (grid[r][c] * prefix) % mod;
        }


        long long suffix = 1;

        for(int i = n * m -1 ; i >= 0 ; i--){
            int r = i / m ;
            int c = i % m ;

            ans[r][c] = (ans[r][c] * suffix) % mod;
            suffix = (grid[r][c] * suffix) % mod;

        }


        return ans;


    }
};