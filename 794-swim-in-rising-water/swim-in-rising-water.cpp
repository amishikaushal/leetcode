class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<bool>> vis(n , vector<bool>(n , false));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        pq.emplace(grid[0][0] , 0 , 0);

        vector<int> dr = {-1 , 0 , 1, 0};
        vector<int> dc = {0 , -1 , 0 , 1};

        while(!pq.empty()){
            auto [time , row , col] = pq.top();
            pq.pop();

            if(row == n -1 && col == n -1){ 
                return time;
            }

            if(vis[row][col] == true) continue;

            vis[row][col] = true;



            for(int i = 0 ; i < 4 ; i++){
                int newr = row + dr[i];
                int newc = col + dc[i];

                if(newr >= 0 && newc < n && newr < n && newc >= 0){
                    pq.emplace(max(time , grid[newr][newc]) , newr , newc);
                }
            }

            
        }
        return -1;
    }
};