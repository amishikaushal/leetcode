class Solution {
public:
    vector<string> ans;
    void backtrack(string num , int target , int ind , long long val , long long prev , string exp){
        if(ind == num.length()){
            if(val == target){
                ans.push_back(exp);
            }
            return;
        }


        for(int i = ind ; i < num.length() ; i++){
            if (i > ind && num[ind] == '0') break;


            string currStr = num.substr(ind, i - ind + 1);
            long long curr = stoll(currStr);


            if(ind == 0){
                backtrack(num , target , i + 1 , curr , curr , currStr);
            }
            else{
                backtrack(num , target , i + 1 , curr + val , curr , exp + "+" +currStr );

                 backtrack(num , target , i + 1 , val - curr , -curr , exp + "-" +currStr );

                 backtrack(num , target , i + 1 ,val - prev + prev * curr , prev * curr , exp + "*" +currStr );
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        backtrack(num, target, 0, 0, 0, "");
        return ans;
    }
};