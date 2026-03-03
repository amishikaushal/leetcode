class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        queue<pair<int , int>> q;


        for(int i = 0; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1){
                    cnt++;
                }
                else if(grid[i][j] == 2){
                    q.push({i , j});
                }
            }
        }

        if(cnt == 0){
            return 0;
        }


        int mins = -1;
        vector<int> dirX = {-1, 1, 0, 0}; 
        vector<int> dirY = {0, 0, -1, 1}; 



        while(!q.empty()){
            int s = q.size();
            mins++;


            for(int i = 0; i < s ; i++){
                auto [x, y] = q.front();
                q.pop();

                for(int i = 0; i < 4 ; i++){
                    int newX = x + dirX[i];
                    int newY = y + dirY[i];

                    
                    if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2; 
                        q.push({newX, newY});
                        cnt--;
                    }
                }

            }


        }
        return (cnt == 0) ? mins : -1;
    }
};