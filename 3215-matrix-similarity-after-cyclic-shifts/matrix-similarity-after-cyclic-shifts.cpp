class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        k = k % m;

        if(k == 0) return 1;
        for(int i=0; i< n ; i++){
            bool iEven=(i&1)==0;
            for(int j=0; j< m; j++)
                if(mat[i][j]!=mat[i][(j+(iEven? m -k:k))% m]) return 0;
        }
        return 1;

        

        for(int i = 0; i < k ; i++){

        }
    }
};