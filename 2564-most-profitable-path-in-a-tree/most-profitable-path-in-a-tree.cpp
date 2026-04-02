class Solution {
public:
    vector<vector<int>> adj;
    vector<int> bobTime;
    int ans = INT_MIN;

    bool findBobPath(int node , int parent , int time , int bob){
        if(node == 0){
            bobTime[node] = time;
            return true;
        }


        for(int nei : adj[node]){
            if(nei == parent) continue;

            if(findBobPath(nei , node , time + 1 , bob)){
                bobTime[node] = time;
                return true;
            }

        }
        return false;
    }

    void dfsAlice(int node , int parent , int time , int curr ,  vector<int>& amount){
        if(time < bobTime[node]){
            curr += amount[node];
        }
        else if(time == bobTime[node]){
            curr += amount[node] / 2;

        }


        bool isLeaf = true;

        for(int nei : adj[node]){
            if(nei == parent) continue;
            isLeaf = false;

            dfsAlice(nei , node , time + 1 , curr , amount);
          
        }

        if(isLeaf){
            ans = max(ans , curr);
        }

    }



    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adj.resize(n);


        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }


        bobTime.assign(n , INT_MAX);

        findBobPath(bob, -1, 0, bob);

 
        dfsAlice(0, -1, 0, 0, amount);

        return ans;


    }
};