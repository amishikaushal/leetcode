class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> vis(n , vector<int> (n , 0));

        priority_queue<tuple<int , int , int> , vector<tuple<int , int , int>> , greater<>> pq;

        pq.emplace(grid[0][0] , 0 , 0);
        vector<int> dr = {-1 , 0 , 1 , 0};
        vector<int> dc = {0 , -1 , 0 , 1};


        while(!pq.empty()){
            auto [time , r , c] = pq.top();
            pq.pop();

            if (vis[r][c]) continue;  
            vis[r][c] = 1;

            if(r == n -1 && c == n -1){
                return time;
            }


            for(int i = 0 ; i < 4 ; i++){
                int newr = r + dr[i];
                int newc = c + dc[i];


                if(newr >= 0 && newr < n && newc >= 0 && newc < n){
                    pq.emplace(max(time , grid[newr][newc]) , newr , newc);
                }
            }

        }

        return -1;

    }
};