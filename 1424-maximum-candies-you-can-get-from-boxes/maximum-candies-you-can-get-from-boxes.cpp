class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
         int n = status.size();

        vector<bool> hasBox(n, false);
        vector<bool> hasKey(n, false);
        vector<bool> used(n, false);

        queue<int> q;

        // initial boxes
        for(int b : initialBoxes) {
            hasBox[b] = true;
            q.push(b);
        }

        int ans = 0;

        while(!q.empty()) {
            int box = q.front();
            q.pop();

           
            if(used[box] || (!status[box] && !hasKey[box]))
                continue;

       
            used[box] = true;
            ans += candies[box];

      
            for(int k : keys[box]) {
                hasKey[k] = true;

               
                if(hasBox[k])
                    q.push(k);
            }

            for(int nb : containedBoxes[box]) {
                hasBox[nb] = true;
                q.push(nb);
            }
        }

        return ans;
        
    }
};