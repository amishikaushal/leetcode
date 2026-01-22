class Solution {
public:
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp, int mod) {
        long long result = 1;
        base %= mod;
        while (exp ) {
            if (exp % 2 == 1) { 
                result = (result * base) % mod;
                exp--;
            }
            base = (base * base) % mod; 
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_count = (n + 1) / 2;
        long long odd_count = n / 2;

        long long pow5 = modPow(5, even_count, MOD);  

        long long pow4 = modPow(4, odd_count, MOD); 
        
        return (pow5 * pow4) % MOD;
    }
};