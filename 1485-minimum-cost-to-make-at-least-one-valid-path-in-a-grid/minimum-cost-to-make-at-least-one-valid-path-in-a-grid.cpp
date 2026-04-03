class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m , vector<int> (n , INT_MAX));

        deque<pair <int , int>> dq;

        dq.push_front({0 , 0});
        dist[0][0] = 0;

        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!dq.empty()){
            auto [i , j] = dq.front();
            dq.pop_front();

            for(int d = 0; d < 4 ; d++){
                int ni = i + dir[d].first;
                int nj = j + dir[d].second;


                if(ni >= m || ni < 0 || nj >= n || nj < 0) continue;

                int cost = (grid[i][j] == d + 1)? 0 : 1;

                if(dist[i][j] + cost < dist[ni][nj]){
                    dist[ni][nj] = dist[i][j] + cost;

                    if(cost == 0){
                        dq.push_front({ni , nj});

                    }
                    else{
                        dq.push_back({ni , nj});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};