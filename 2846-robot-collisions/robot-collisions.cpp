class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<tuple<int , int , char , int>>  robots;
    for (int i = 0; i < n; i++) {
        robots.push_back({positions[i], healths[i], directions[i], i});
    }

    // Step 2: Sort by position
    sort(robots.begin(), robots.end());

    // Stack to keep indices of robots moving right
    stack<int> st;

    // Store final healths
    vector<int> finalHealth(n, 0);

    for (int i = 0; i < n; i++) {
        auto& [pos, health, dir, idx] = robots[i];

        if (dir == 'R') {
            st.push(i);
        } else {
            // dir == 'L'
            while (!st.empty()) {
                auto& [posR, healthR, dirR, idxR] = robots[st.top()];

                if (healthR < health) {
                    // R dies
                    st.pop();
                    health--; // L loses 1
                } 
                else if (healthR == health) {
                    // both die
                    st.pop();
                    health = 0;
                    break;
                } 
                else {
                    // L dies
                    healthR--; // R loses 1
                    health = 0;
                    break;
                }
            }

            if (health > 0) {
                finalHealth[idx] = health;
            }
        }
    }


    while (!st.empty()) {
        int i = st.top();
        st.pop();
        auto& [pos, health, dir, idx] = robots[i];
        finalHealth[idx] = health;
    }

    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (finalHealth[i] > 0) {
            result.push_back(finalHealth[i]);
        }
    }

    return result;
        

    }
};