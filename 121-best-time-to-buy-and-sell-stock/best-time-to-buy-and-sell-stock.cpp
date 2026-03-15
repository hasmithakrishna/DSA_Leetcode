class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minbuy = INT_MAX;
        for(int i=0; i<prices.size();i++){
            if(prices[i]<minbuy){
                minbuy = prices[i];
            }
            int profit = prices[i] - minbuy;
            if(profit>maxprofit){
                maxprofit = profit;
            }
        }
        return maxprofit;
        
    }
};