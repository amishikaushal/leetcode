class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int , int>> pq;

        int n = arr.size();
        vector<int>  ans;

        for(int i = 0; i < n ; i++){
            int d = abs(arr[i] - x);

            pq.push({d , arr[i]});

            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin() , ans.end());

        return ans;
    }
};