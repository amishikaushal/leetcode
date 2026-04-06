class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
            unordered_map<string , vector<pair<string , double>>> g1 , g2;


            for(int i = 0; i < pairs1.size() ; i++){
                string u = pairs1[i][0], v = pairs1[i][1];
                double r = rates1[i];

                g1[u].push_back({v, r});
                g1[v].push_back({u, 1.0 / r});
            }


            for(int i = 0; i < pairs2.size() ; i++){
                 string u = pairs2[i][0], v = pairs2[i][1];
                    double r = rates2[i];

                    g2[u].push_back({v, r});
                    g2[v].push_back({u, 1.0 / r});
            }


            unordered_map<string, double> best1;
        queue<string> q;

        best1[initialCurrency] = 1.0;
        q.push(initialCurrency);

        while (!q.empty()) {
            string curr = q.front(); q.pop();

            for (auto &[next, rate] : g1[curr]) {
                if (!best1.count(next) || best1[next] < best1[curr] * rate) {
                    best1[next] = best1[curr] * rate;
                    q.push(next);
                }
            }
        }


        double ans = 0.0;

        for (auto &[start, amount] : best1) {

            unordered_map<string, double> best2;
            queue<string> q2;

            best2[start] = amount;
            q2.push(start);

            while (!q2.empty()) {
                string curr = q2.front(); q2.pop();

                for (auto &[next, rate] : g2[curr]) {
                    if (!best2.count(next) || best2[next] < best2[curr] * rate) {
                        best2[next] = best2[curr] * rate;
                        q2.push(next);
                    }
                }
            }

            ans = max(ans, best2[initialCurrency]);
        }

        return ans;
        
    }
};