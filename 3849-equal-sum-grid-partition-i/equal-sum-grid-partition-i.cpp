class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return false;
        
        int n = grid.size();
        int m = grid[0].size();

        long long total = 0;
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                total += grid[r][c];
            }
        }

     
        if(total % 2 != 0) return false;

        long long target = total / 2;
        long long currentSum = 0;

      
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < m; j++) {
                currentSum += grid[i][j];
            }
            if(currentSum == target) return true;
        }

        currentSum = 0;
        
     
        for(int j = 0; j < m - 1; j++) {
            for(int i = 0; i < n; i++) {
                currentSum += grid[i][j];
            }
            if(currentSum == target) return true;
        }

        return false;


    }
};