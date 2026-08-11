#include <vector>
using namespace std;

class Solution {
public:
    // 1. The platform calls THIS function (2 arguments expected)
    int search(vector<int>& nums, int target) {
        // We pass the vector, the starting index (0), the ending index, and the target
        return searchHelper(nums, 0, nums.size() - 1, target);
    }

private:
    // 2. Your custom recursive logic goes in a helper function (4 arguments)
    int searchHelper(vector<int>& nums, int si, int ei, int target) {
        if(si > ei) {
            return -1;
        }
        
        int mid = si + (ei - si) / 2;
        
        if(nums[mid] == target) {
            return mid;
        }
        
        if(nums[si] <= nums[mid]) {
            if(nums[si] <= target && target <= nums[mid]) {
                return searchHelper(nums, si, mid - 1, target); 
            } else {
                return searchHelper(nums, mid + 1, ei, target); 
            }
        } 
        else {
            if(nums[mid] <= target && target <= nums[ei]) {
                return searchHelper(nums, mid + 1, ei, target); 
            } else {
                return searchHelper(nums, si, mid - 1, target); 
            }
        }
    }
};