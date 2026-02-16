class Solution {
public:
    int reverseBits(int n) {
        unsigned int num = n;     
        unsigned int result = 0;

        for (int i = 0; i < 32; i++) {
            result <<= 1;         
            result |= (num & 1);  
            num >>= 1;          
        }

        return result;  
    }
};