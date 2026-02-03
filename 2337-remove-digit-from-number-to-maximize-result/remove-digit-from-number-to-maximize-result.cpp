class Solution {
public:
    string removeDigit(string number, char digit) {
        string maxi = "";
        int n = number.length();

        for (int i = 0; i < n; i++) {
            if (number[i] == digit) {
                string newnum = number.substr(0, i) + number.substr(i + 1);

                if (maxi == "" || newnum > maxi) {
                    maxi = newnum;
                }
            }
        }
        return maxi;
    }
};