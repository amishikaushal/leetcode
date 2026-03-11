class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0){
            return 1;
        }

        int bits = 32 - __builtin_clz(n);

        int mask = (1 << bits ) - 1;

        return n ^ mask;
    }
};