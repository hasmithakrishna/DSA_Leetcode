class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minbuy = INT_MAX;
        int maxim = 0;
        for(int i=0; i<prices.size(); i++){
            if(prices[i] < minbuy){
                minbuy = prices[i];
            }
            int profit = prices[i] - minbuy;
            if(profit > maxim) maxim = profit;
        }
        return maxim;
    }
};