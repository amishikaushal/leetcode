class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> incoming(n , 0);


        for(int i = 0; i < n ; i++){
            incoming[edges[i]] +=  i;
        }
        long long  maxi = -1;
        int ans = 0;


        for(int i = 0; i < n ; i++){
            if(incoming[i] > maxi){
                ans = i;
                maxi = incoming[i];
            }
        }

        return ans;
    }
};