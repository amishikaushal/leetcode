class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(auto &it : operations){
            if(it != "C" && it != "D" && it != "+"){
                st.push(stoi(it));
            }
            else if(it == "C"){
               st.pop(); 
            }
            else if(it == "D"){
                int n = 2 * st.top();
                st.push(n);
            }
            else{
                int first = st.top();
                st.pop();

                int second = st.top();

                st.push(first);
                st.push(first + second);
            }


        }
        int sum = 0;

        while(!st.empty()){
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};