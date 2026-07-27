class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt = 0;
        int write = 0;
        int last = chars[0];

        for (int i = 0; i < chars.size(); i++) {

            if (last == chars[i]) {
                cnt++;
            } else {

                chars[write++] = last;

                if (cnt > 1) {
                    string s = to_string(cnt);
                    for (auto c : s) {
                        chars[write++] = c;
                    }
                }

                last = chars[i];
                cnt = 1;
            }
        }

        chars[write++] = last;
        if (cnt > 1) {
            string s = to_string(cnt);
            for (auto c : s) {
                chars[write++] = c;
            }
        }

        return write;
    }
};