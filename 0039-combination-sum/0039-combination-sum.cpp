class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int target, int index,
               vector<int>& temp) {

        // Target reached
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // Target exceeded
        if (target < 0) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Take
            temp.push_back(candidates[i]);

            // i, NOT i+1
            solve(candidates, target - candidates[i], i, temp);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;

        solve(candidates, target, 0, temp);

        return ans;
    }
};