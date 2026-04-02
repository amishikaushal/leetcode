class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> redAdj(n);
        vector<vector<int>> blueAdj(n);


        for(auto &it : redEdges){
            redAdj[it[0]].push_back(it[1]);

        }

        for(auto &it : blueEdges){
            blueAdj[it[0]].push_back(it[1]);
            
        }

        vector<int> ans(n , -1);

        vector<vector<bool>> vis(n , vector<bool>(2 , false));


        queue<pair< int , int>> q;

        q.push({0 , 0});
        q.push({0 , 1});

        vis[0][0] = vis[0][1] = true;

        int steps = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto [node , color] = q.front();
                q.pop();

                if(ans[node] == -1){
                    ans[node] = steps;
                }


                if(color == 0){
                    for(int nei : blueAdj[node]){
                        if(!vis[nei][1]){   
                            vis[nei][1] = true;
                            q.push({nei , 1});
                        }
                    }
                }
                else{
                    for(int nei : redAdj[node]){
                        if(!vis[nei][0]){
                            vis[nei][0] = true;
                            q.push({nei , 0});
                        }
                    }
                }
            }

            steps++;
        }

        return ans;

    }
};