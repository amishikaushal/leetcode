class Solution {
public:
    /*int solve(int i , int j ,vector<vector<int>> &dp , vector<vector<int>>& obstacleGrid){
        if(i == 0 && j == 0){
            return 1;
        }

        if(i < 0 || j < 0){
            return 0;
        }

        if(obstacleGrid[i][j] == 1){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int up = solve(i -1 , j , dp , obstacleGrid);
        int left = solve(i , j -1 , dp ,obstacleGrid);

        return dp[i][j] = up + left;


    }*/
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();

        int m = obstacleGrid[0].size();


        if(obstacleGrid[0][0] == 1) return 0;

        vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 0));

        dp[0][0] = 1;

        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else{
                    if (i > 0) dp[i][j] += dp[i - 1][j];
                    if (j > 0) dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[n -1][m-1];
    }
};