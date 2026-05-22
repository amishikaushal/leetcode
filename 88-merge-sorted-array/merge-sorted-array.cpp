class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;

        vector<int> ans;


        while(i < n && j < m){
            if(nums1[j] > nums2[i]){
                ans.push_back(nums2[i]);
                i++;
            }
            else{
                ans.push_back(nums1[j]);
                j++;
            }
        }


        while(i < n){
            ans.push_back(nums2[i]);
            i++;

        }


        while(j < m){
            ans.push_back(nums1[j]);
            j++;
        }


        nums1 = ans;
    }
};