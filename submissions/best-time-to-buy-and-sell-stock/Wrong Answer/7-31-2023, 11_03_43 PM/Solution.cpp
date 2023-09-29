// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest=prices[0],maxest=prices[0];
        for(int i=1;i<prices.size();i++){
            if(lowest>prices[i]){
                lowest=prices[i];
                maxest=prices[i];
            }
            maxest=max(maxest,prices[i]);
        }
        return maxest-lowest;
    }
};