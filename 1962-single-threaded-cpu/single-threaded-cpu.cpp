class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n= tasks.size();

        for(int i = 0; i < n; i++){
            tasks[i].push_back(i);
        }

        sort(tasks.begin() , tasks.end());

        priority_queue<pair<int , int> ,  vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> ans;

        int i = 0;
        long long time  = tasks[0][0];


        while(i < n || !pq.empty()){
            while(i < n && time >= tasks[i][0]){
                pq.push({tasks[i][1] , tasks[i][2]});
                i++;
            }

            if(pq.empty()){
                time = tasks[i][0];
            }
            else{
                auto [proc , idx] = pq.top();
                pq.pop();
                ans.push_back(idx);
                time += proc;
            }
        }
        return ans;




    }
};