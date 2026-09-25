class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        int col0 = 1;

        // Step 1: Mark rows and columns
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(matrix[i][j] == 0) {

                    // Mark row
                    matrix[i][0] = 0;

                    // Mark column
                    if(j != 0) {
                        matrix[0][j] = 0;
                    }
                    else {
                        col0 = 0;
                    }
                }
            }
        }

        // Step 2: Use markers
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {

                if(matrix[i][j] != 0) {

                    if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        // Step 3: Handle first row
        if(matrix[0][0] == 0) {

            for(int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle first column
        if(col0 == 0) {

            for(int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};