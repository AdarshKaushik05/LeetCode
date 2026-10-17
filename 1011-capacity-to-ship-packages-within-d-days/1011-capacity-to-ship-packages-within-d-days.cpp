class Solution {
public:

    int findMax(vector<int>& weights){
        int maxi = INT_MIN;

        for(int i = 0; i < weights.size(); i++){
            maxi = max(maxi, weights[i]);
        }

        return maxi;
    }

    int findSum(vector<int>& weights){
        int sum = 0;

        for(int i = 0; i < weights.size(); i++){
            sum += weights[i];
        }

        return sum;
    }

    int calDays(vector<int>& weight, int capacity){
        int days = 1;
        int load = 0;

        for(int i = 0; i < weight.size(); i++){
            if(load + weight[i] > capacity){
                days++;
                load = weight[i];
            }
            else{
                load += weight[i];
            }
        }

        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {

        int low = findMax(weights);
        int high = findSum(weights);

        while(low <= high){

            int mid = low + (high - low) / 2;

            int noOfDays = calDays(weights, mid);

            if(noOfDays <= days){
                high = mid - 1;
            } 
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};