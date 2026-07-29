class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(n == 1 && grid[0][0] == 0){
            return 1;
        }


        if(grid[0][0] != 0 || grid[n-1][n-1] != 0){
            return -1;
        }


        vector<vector<int>> dirs= {{-1,1},{-1,0},{-1,-1},{0,1},{0,-1},{1,1},{1,-1},{1,0}};


        queue<pair<int , pair<int , int>>> q;

        vector<vector<int>> dist(n , vector<int>(n , 1e9));

        

        q.push({1 , {0 , 0}});
        grid[0][0] = 1;

        while(!q.empty()){
            int  steps = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;

            q.pop();


            if(r == n-1 && c == n-1){
                return steps;
            }

            for(vector<int> dr: dirs){
                int nr = r + dr[0];
                int nc = c + dr[1];


                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 ){
                    grid[nr][nc] = 1;
                    q.push({1 + steps , {nr , nc}});
                }
            }
        }
        return -1;
    }
};