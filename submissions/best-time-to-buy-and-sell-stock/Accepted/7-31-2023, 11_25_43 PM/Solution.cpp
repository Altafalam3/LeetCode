// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest=INT_MAX,maxest=0,profit=0;
        for(int i=0;i<prices.size();i++){
            if(lowest>prices[i]){
                lowest=prices[i];
            }
            maxest=prices[i]-lowest;

            profit=max(profit,maxest);
        }
        return profit;
    }
};