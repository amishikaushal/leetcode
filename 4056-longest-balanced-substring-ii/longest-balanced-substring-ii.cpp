class Solution {
public:
    long long pack(int x, int y) {
        return ( (long long)x << 32 ) ^ (unsigned long long)(y);
    }

    int longestBalanced(string s) {
        int n = s.length();
        int maxi = 0;

        // handle single character streak
        int streak = 1;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i-1]) streak++;
            else {
                maxi = max(maxi, streak);
                streak = 1;
            }
        }
        maxi = max(maxi, streak);

        int A = 0, B = 0, C = 0;

        unordered_map<long long,int> mapABC, mapAB, mapBC, mapCA;

        mapABC[pack(0,0)] = -1;
        mapAB[pack(0,0)] = -1;
        mapBC[pack(0,0)] = -1;
        mapCA[pack(0,0)] = -1;

        for(int i = 0; i < n; i++){
            if(s[i] == 'a') A++;
            else if(s[i] == 'b') B++;
            else C++;

        
            long long key = pack(B-A, C-A);
            if(mapABC.count(key))
                maxi = max(maxi, i - mapABC[key]);
            else
                mapABC[key] = i;

       
            key = pack(A-B, C);
            if(mapAB.count(key))
                maxi = max(maxi, i - mapAB[key]);
            else
                mapAB[key] = i;

           
            key = pack(B-C, A);
            if(mapBC.count(key))
                maxi = max(maxi, i - mapBC[key]);
            else
                mapBC[key] = i;

  
            key = pack(C-A, B);
            if(mapCA.count(key))
                maxi = max(maxi, i - mapCA[key]);
            else
                mapCA[key] = i;
        }

        return maxi;
    }
};
