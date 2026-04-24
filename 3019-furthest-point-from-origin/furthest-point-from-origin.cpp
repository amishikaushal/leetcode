class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();

        int l = 0;
        int r = 0;
        int maxi = 0;
        int mini = 0;
        int cnt = 0;


        for(auto &ch : moves){
            if(ch == 'L'){
                l++;
            }
            else if(ch == 'R'){
                r++;
            }
            else{
                cnt++;
            }
        }

        if(l > r){
            maxi =l;
            mini = r;
        }
        else{
            maxi = r;
            mini = l;
        }


        return maxi + cnt - mini;
    }
};