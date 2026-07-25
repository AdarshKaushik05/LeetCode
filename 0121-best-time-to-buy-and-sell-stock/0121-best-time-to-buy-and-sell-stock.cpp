class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int bestBuy[100000];
        bestBuy[0] = INT_MAX;

        for(int i = 1; i < n; i++){
            bestBuy[i] = min( bestBuy[i-1], prices[i-1]);

        }

        int maxProfit = 0;
        for(int i = 0; i < n; i++){
            int currProfit = prices[i] - bestBuy[i];
            maxProfit = max(maxProfit,currProfit);
        }
        
        return maxProfit;
        
    }

};