class Solution {
public:
    void dfs(int r , int c , vector<vector<int>> &vis , vector<vector<int>>& mat , vector<int> delrow , vector<int> delcol){
        vis[r][c] = 1; 
        int n = mat.size();
        int m = mat[0].size();
      
        for(int i = 0; i < 4 ; i++) {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i]; 
            
            if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && mat[nrow][ncol] == 1) {
                dfs(nrow, ncol, vis, mat, delrow, delcol); 
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();

        int m = grid[0].size();

        vector<vector<int>> vis(n , vector<int>(m , 0));

        vector<int> delrow = {-1 , 0 , 1 , 0};
        vector<int> delcol = {0 , -1 , 0 , 1 };


        for(int i = 0 ; i < n ; i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                dfs(i , 0 , vis , grid , delrow , delcol);
            }

            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                dfs(i , m -1 , vis , grid , delrow , delcol);
            }
        }


        for(int i = 0 ; i < m ; i++){
            if(grid[0][i] == 1 && !vis[0][i]){
                dfs(0 , i , vis , grid , delrow , delcol);
            }

            if(grid[n -1][i] == 1 && !vis[n -1][i]){
                dfs(n -1 , i , vis , grid , delrow , delcol);
            }
        }

        int cnt = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};