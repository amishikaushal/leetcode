class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int t = 0;
        int c = 0;
        int start = 0;

        for(int i = 0 ; i < n ; i++){
            int net = gas[i] - cost[i];

            t += net;
            c += net;

            if(c < 0){
                start = i + 1;
                c = 0;
            }
        }

        return t < 0 ? -1 : start;
    }
};