class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin() , nums.end());
        int longest = 0;

        for(auto &it : seen){
            if(seen.find(it - 1) == seen.end()){
                int x = it;
                int cnt = 1;


                while(seen.find(x + 1) != seen.end()){
                    cnt++;
                    x = x +1 ;
                }


                longest = max(cnt , longest);
            }
        }
        return longest;


    }
};