class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 1;
        for(int i = 0; i < n; i++){
            if(nums[i]==ans){
                ans++;
            }
        }
        unordered_map<int,int>m;
        int repeat;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            if(m[nums[i]] >= 2){
                repeat = nums[i];
                break;
            }
        }
        return {repeat,ans};
    }
};