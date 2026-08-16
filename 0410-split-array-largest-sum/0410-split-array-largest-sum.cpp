class Solution {
public:
    bool canSplit(vector<int>& nums, int k, long long maxSum) {
        int parts = 1;
        long long sum = 0;

        for (int num : nums) {
            if (sum + num > maxSum) {
                parts++;
                sum = num;
            } else {
                sum += num;
            }
        }

        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long left = 0;
        long long right = 0;

        for (int num : nums) {
            left = max(left, (long long)num);
            right += num;
        }

        while (left < right) {
            long long mid = left + (right - left) / 2;

            if (canSplit(nums, k, mid)) {
                right = mid;       // try smaller
            } else {
                left = mid + 1;    // need bigger
            }
        }

        return left;
    }
};