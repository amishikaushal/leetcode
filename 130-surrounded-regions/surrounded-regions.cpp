class Solution {
public:
    void dfs(int r , int c , vector<vector<int>> &vis , vector<vector<char>>& mat , vector<int> delrow , vector<int> delcol){
        vis[r][c] = 1; 
        int n = mat.size();
        int m = mat[0].size();
      
        for(int i = 0;i<4;i++) {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i]; 
            
            if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, mat, delrow, delcol); 
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n , vector<int>(m , 0));

        vector<int> delrow = {-1 , 0 , 1 , 0};
        vector<int> delcol = {0 , -1 , 0 , 1 };


        for(int i = 0 ; i < n ; i++){
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i , 0 , vis , board , delrow , delcol);
            }

            if(board[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(i , m -1 , vis , board , delrow , delcol);
            }
        }


        for(int i = 0 ; i < m ; i++){
            if(board[0][i] == 'O' && !vis[0][i]){
                dfs(0 , i , vis , board , delrow , delcol);
            }

            if(board[n -1][i] == 'O' && !vis[n -1][i]){
                dfs(n -1 , i , vis , board , delrow , delcol);
            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == 'O' && vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }

    }
};