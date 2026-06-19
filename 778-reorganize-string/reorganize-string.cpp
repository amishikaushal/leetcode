class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<int , int> mpp;

        for(auto &c : s){
            mpp[c]++;
        }

        priority_queue<pair<int , char>> pq;

        for(auto &[ch, freq] : mpp){
            pq.push({freq , ch});
        }


        string res;

        while(pq.size() >= 2){
            auto [freq1 , ch1] = pq.top();
            pq.pop();


            auto [freq2 , ch2] = pq.top();
            pq.pop();

            res += ch1;
            res += ch2;

            if(--freq1 > 0) pq.push({freq1 , ch1});
             if(--freq2 > 0) pq.push({freq2 , ch2});


        }


        if(!pq.empty()){
            auto [fr , ch] = pq.top();
            if(fr > 1) return "";

            res += ch;
        }
        return res;
    }
};