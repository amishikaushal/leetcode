class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int> mpp;

        int n = nums2.size();
        stack<int> st;

        for(int i = n -1 ; i >= 0 ; i--){
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }

            if(!st.empty()){
                mpp[nums2[i]] = st.top();
            }
            else{
                mpp[nums2[i]] = -1;
            }


            st.push(nums2[i]);
        }
        vector<int> ans;


        for(auto num : nums1){
            ans.push_back(mpp[num]);
        }
        return ans;
        
    }
};