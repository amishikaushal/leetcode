class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();

        vector<int> mask(n);

        for(int i = 0; i < n ; i++){
            int m = 0;

             for(char c:words[i])
                m |= (1<<(c-'a'));
            
            mask[i] = m;
        }
        int ans = 0;

        for(int i = 0; i < n ; i++){
            for(int j = i +1 ; j < n ; j++){
                if((mask[i] & mask[j]) == 0){
                    ans=max(ans,
                        (int)words[i].size()*
                        (int)words[j].size());
                    
                }
            }
        }
        return ans;
    }
};