class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0){
            return false;
        }
        

        map<int , int> frq;
        for(auto it : hand){
            frq[it]++;
        }


        for(auto &it : frq){
            int start = it.first;
            int cnt = it.second;

            if(cnt > 0){
                for(int i = 0; i < groupSize; i++){
                    
                    if(frq[start + i] < cnt)
                        return false;
                    
                    frq[start + i] -= cnt;
                }
            }
        }

        return true;

    }
};