class Solution {
public:
    int gcd(int a , int b){
        return b == 0 ? a : gcd(b , a % b);
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int g = nums[0];
        for(int i = 1; i < n ; i++){
            g = gcd(g , nums[i]);
        }


        if(g != 1) return -1;
        int ones = 0;


        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 1){
                ones++;
            }
        }

        if(ones > 0){
            return n - ones;
        }


        int minLen = n;

        for(int i = 0 ; i < n ; i++){
            int gr = nums[i];

            for(int j = i +1 ; j < n ; j++){
                gr = gcd(gr , nums[j]);
                if (gr == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }

        return (minLen - 1) + (n - 1);


    }
};