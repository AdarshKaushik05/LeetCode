class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int index, vector<int>& temp) {

        // Every state is an answer
        ans.push_back(temp);

        for (int i = index; i < nums.size(); i++) {

            // Take
            temp.push_back(nums[i]);

            solve(nums, i + 1, temp);

            // Backtrack
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;

        solve(nums, 0, temp);

        return ans;
    }
};