class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> mpp;

        for (auto it : words) {
            mpp[it]++;
        }
        auto cmp = [](pair<int, string> a, pair<int, string> b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>,
                       decltype(cmp)>
            pq(cmp);

        for (auto it : mpp) {
            pq.push({it.second, it.first});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> ans;

        while (!pq.empty()) {
            string curr = pq.top().second;
            pq.pop();
            ans.push_back(curr);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};