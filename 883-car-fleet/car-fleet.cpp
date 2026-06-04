class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int , int>> dist;
        int n = position.size();

        for(int i = 0; i < n ; i++){
            dist.push_back({position[i] , speed[i]});
        }
        sort(dist.begin() , dist.end());

        stack<double>st;

        for(int i = n -1 ; i >= 0; i--){
            double time = (double)(target - dist[i].first)/ dist[i].second;

            if(st.empty() || time > st.top()){
                st.push(time);
            }
        }
        return st.size();
    }
};