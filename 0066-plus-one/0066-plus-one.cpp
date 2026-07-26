class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for (int i = digits.size() - 1; i >= 0; i--) {

            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i] = digits[i] + 1;
                return digits;
            }
        }

        vector<int> res(digits.size() + 1, 0);
        res[0] = 1;

        return res;
    }
};