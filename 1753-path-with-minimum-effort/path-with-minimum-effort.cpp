class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n , vector<int>(m , INT_MAX));

        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        vector<int> delrow = {-1, 0 , 1 , 0};
        vector<int> delcol = {0, -1 , 0 , 1};

        pq.push({0 , {0,0}});
        dist[0][0] = 0;


        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;


            if(row == n-1 && col == m-1){
                return effort;
            }

            for(int i = 0; i < 4 ; i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int diff = abs(heights[row][col] - heights[nr][nc]);
                    int newe = max(diff , effort);

                    if(newe < dist[nr][nc]){
                        dist[nr][nc] = newe;
                        pq.push({newe , {nr , nc}});
                    }
                }
            }
        }
        return -1;
    }
};