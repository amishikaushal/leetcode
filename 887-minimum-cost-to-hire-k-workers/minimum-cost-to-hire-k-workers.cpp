class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
               vector<pair<double, int>> q;

        for (int i = 0; i < wage.size(); i++) {
            double ratio = (double)wage[i] / quality[i];
            q.push_back({ratio, quality[i]});
        }

        sort(q.begin(), q.end());

        priority_queue<int> pq;
        int qualitySum = 0;
        double ans = DBL_MAX;

        for (auto [rat, qual] : q) {

            qualitySum += qual;
            pq.push(qual);

            if (pq.size() > k) {
                qualitySum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                ans = min(ans, rat * qualitySum);
            }
        }

        return ans;
    }
};