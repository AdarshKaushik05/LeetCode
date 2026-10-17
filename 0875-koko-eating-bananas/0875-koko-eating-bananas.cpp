class Solution {
public:
    int findMax(vector<int> &piles){
        int maxi = INT_MIN;
        int n = piles.size();
        for(int i = 0; i <n; i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
    long long calTotalH(vector<int> &piles, int hourly){
        long long totalH = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++){
            totalH += ceil((double)piles[i] / (double)hourly);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);
        while(low <= high){
            int mid = low + (high - low)/2;
            long long totalH = calTotalH(piles,mid);
            if(totalH <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};