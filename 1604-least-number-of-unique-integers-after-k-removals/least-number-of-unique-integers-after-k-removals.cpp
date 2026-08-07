class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int , int> mpp;


        for(auto it : arr){
            mpp[it]++;
        }

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;

        for(auto [val , freq] : mpp){
            pq.push({freq , val});
        }

        while(k && !pq.empty()){
            
            auto [freq , val] = pq.top();
            pq.pop();
            freq--;


            if(freq > 0){
                pq.push({freq , val});
            }

            k--;
        }

        return pq.size();


    }
};