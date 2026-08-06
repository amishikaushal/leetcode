class Solution {
public:
    int isproduct(int n){
        int m = 1;
        while(n){
            int digit = n % 10;
            m *= digit;
            n /= 10;
        }

        return m;
    }
    int smallestNumber(int n, int t) {
        for(int i = n ; i <= 100; i++){
            if(isproduct(i) % t == 0){
                return i;
            }
        }

        return -1;
    }
};