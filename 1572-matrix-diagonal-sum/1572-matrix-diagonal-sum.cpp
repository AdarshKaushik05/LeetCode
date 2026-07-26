class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            // Primary diagonal
            sum += mat[i][i];

            // Secondary diagonal (only if it's not the same cell)
            if (i != n - i - 1) {
                sum += mat[i][n - i - 1];
            }
        }

        return sum;
    }
};