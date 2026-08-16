class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        k -= n;

        for(int i = n-1; i>=0; i--){
            int add = min(25,k);
            ans[i] += add;
            k -= add;
        }
        return ans;
        
    }
};