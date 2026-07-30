class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        // Compute all window sums
        vector<int> window(n - k + 1);

        int sum = 0;

        for (int i = 0; i < n; i++) {

            sum += nums[i];

            if (i >= k)
                sum -= nums[i - k];

            if (i >= k - 1)
                window[i - k + 1] = sum;
        }

        int m = window.size();

        // left[i] = index of best window from 0...i
        vector<int> left(m);

        left[0] = 0;

        for (int i = 1; i < m; i++) {

            if (window[i] > window[left[i - 1]])
                left[i] = i;
            else
                left[i] = left[i - 1];
        }

        // right[i] = index of best window from i...m-1
        vector<int> right(m);

        right[m - 1] = m - 1;

        for (int i = m - 2; i >= 0; i--) {

            if (window[i] >= window[right[i + 1]])
                right[i] = i;
            else
                right[i] = right[i + 1];
        }

        vector<int> ans;

        int best = 0;

        // Try every middle window
        for (int mid = k; mid < m - k; mid++) {

            int l = left[mid - k];
            int r = right[mid + k];

            int total = window[l] + window[mid] + window[r];

            if (total > best) {

                best = total;
                ans = {l, mid, r};
            }
        }

        return ans;
    }
};