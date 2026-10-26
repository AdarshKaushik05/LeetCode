class Solution {
public:
    vector<string> ans;

    void solve(string s, int open, int close, int n) {

        // Base case
        if (s.length() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // We can add '(' if open < n
        if (open < n) {
            solve(s + '(', open + 1, close, n);
        }

        // We can add ')' only if close < open
        if (close < open) {
            solve(s + ')', open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        solve("", 0, 0, n);
        return ans;
    }
};