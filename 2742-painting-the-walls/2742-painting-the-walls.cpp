class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();

        vector<int> dp(n + 1, 1e9);

        dp[0] = 0;

        for(int i = 0; i < n; i++) {

            for(int j = n; j >= 1; j--) {

                int previous = max(0, j - time[i] - 1);

                dp[j] = min(dp[j], dp[previous] + cost[i]);
            }
        }

        return dp[n];
    }
};