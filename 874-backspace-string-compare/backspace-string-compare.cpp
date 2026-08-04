class Solution {
public:
    string process(string s) {
        string res;

        for (char c : s) {
            if (c == '#') {
                if (!res.empty())
                    res.pop_back();
            } else {
                res.push_back(c);
            }
        }

        return res;
    }
    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }
};