class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        
        if (k == 0) {
            return nums1 == nums2 ? 0 : -1;
        }
        
        long long sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += nums1[i];
            sum2 += nums2[i];
        }
        
        if (sum1 != sum2) return -1;
        
        long long positiveUnits = 0;
        long long negativeUnits = 0;
        
        for (int i = 0; i < n; i++) {
            long long diff = nums2[i] - nums1[i];
            
            if (abs(diff) % k != 0) return -1;
            
            if (diff > 0) positiveUnits += diff / k;
            else negativeUnits += (-diff) / k;
        }
        
        if (positiveUnits != negativeUnits) return -1;
        
        return positiveUnits;
    }
};
