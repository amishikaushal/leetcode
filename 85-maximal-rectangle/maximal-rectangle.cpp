class Solution {
public:
    vector<int> prevS(vector<int>& nums){
        int n = nums.size();

        vector<int> ans(n , -1);
        stack<int> st;

        for(int i = 0 ; i < n ; i++){
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

    vector<int> nextS(vector<int>& nums){
        int n = nums.size();

        vector<int> ans(n , n);
        stack<int> st;

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
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> prev = prevS(heights);
        vector<int> next = nextS(heights);

        int maxi = 0;


        for(int i = 0 ; i < n ; i++){
            int h = heights[i];
            int w = next[i] - prev[i] - 1;

            int area = h * w;

            maxi = max(maxi ,area);
        }

        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
         if (matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m , 0);
        int maxi = 0;


        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == '1'){
                    heights[j] += 1;
                }
                else{
                    heights[j] = 0;
                }
            }

            maxi = max(maxi , largestRectangleArea(heights));
        }

        return maxi;
    }
};