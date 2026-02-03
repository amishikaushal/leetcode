class Solution {
public:

    vector<int> nse(vector<int>& nums){
        stack<int> st;
        
        int n = nums.size();
        vector<int> ans(n , n);


        for(int i = n -1 ; i >= 0 ; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }


            if(!st.empty()){
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> psee(vector<int>& nums){
        stack<int> st;
        
        int n = nums.size();
        vector<int> ans(n , -1);


        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }


            if(!st.empty()){
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }


    vector<int> nge(vector<int>& nums){
        stack<int> st;
        
        int n = nums.size();
        vector<int> ans(n , n);


        for(int i = n -1 ; i >= 0 ; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }


            if(!st.empty()){
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> pge(vector<int>& nums){
        stack<int> st;
        
        int n = nums.size();
        vector<int> ans(n , -1);


        for(int i = 0; i < n ; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }


            if(!st.empty()){
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> nextSmaller = nse(nums);
        vector<int> prevSmaller = psee(nums);

        vector<int> nextGreater = nge(nums);
        vector<int> prevGreater = pge(nums);

        long long ans = 0;

        for(int i = 0 ; i < n ; i++){
            long long leftmin = i - prevSmaller[i];

            long long rightmin =  nextSmaller[i] - i;

            long long contrimin = leftmin * rightmin * nums[i];

            long long leftmax = i - prevGreater[i];

            long long rightmax = nextGreater[i] - i;

            long contrimax = leftmax * rightmax * nums[i];


            ans += (contrimax - contrimin);
        }

        return ans;

    }
};