class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = 0;
        int r = 0;

        for(int i = 0 ; i < k ; i++){
            l += cardPoints[i];
        }

        int maxi = 0;
        maxi = l;

        int rind = n -1;
        
        for(int i = k -1 ; i >= 0 ; i--){
            l -= cardPoints[i];

            r += cardPoints[rind];
            rind--;


            maxi = max(maxi , l + r);
        }
        return maxi;

    }
};