class Solution {
public:

    int findMax(vector<int>& bloomDay) {
        int maxi = INT_MIN;

        for(int i = 0; i < bloomDay.size(); i++) {
            maxi = max(maxi, bloomDay[i]);
        }

        return maxi;
    }

    int findMin(vector<int>& bloomDay) {
        int mini = INT_MAX;

        for(int i = 0; i < bloomDay.size(); i++) {
            mini = min(mini, bloomDay[i]);
        }

        return mini;
    }

    bool possible(vector<int>& bloomDay, int day, int m, int k) {

        int bouquets = 0;
        int flowers = 0;

        for(int i = 0; i < bloomDay.size(); i++) {

            if(bloomDay[i] <= day) {
                flowers++;

                if(flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            }
            else {
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long required = (long long)m * k;

        if(required > bloomDay.size())
            return -1;

        int low = findMin(bloomDay);
        int high = findMax(bloomDay);

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(possible(bloomDay, mid, m, k)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};