class Solution {
public:
    bool isGood(int x) {
        bool diff = false;

        while (x > 0) {
            int d = x % 10;

            if (d == 3 || d == 4 || d == 7) return false;

            if (d == 2 || d == 5 || d == 6 || d == 9)
                diff = true;

            x /= 10;
        }

        return diff;
    }

    int rotatedDigits(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (isGood(i)) ans++;
        }

        return ans;
    }
};