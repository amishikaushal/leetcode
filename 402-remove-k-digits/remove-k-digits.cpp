class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        string ans = ""; 
        int n = num.length();

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && k > 0 && st.top() > num[i]){
                st.pop();
                k--;
            }
            
            st.push(num[i]);


           
        }

        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }


        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());


        int i = 0;
         while (i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);


        if(ans.empty()){
            return "0";
        }


        return ans;
        



    }
};