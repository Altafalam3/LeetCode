// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBanana=0;
        for(auto pile:piles){
            maxBanana = max(maxBanana, pile);
        }

        int hrs=INT_MAX;
        for(int k=1;k<=maxBanana; k++){
            long long currHr=0;
            for(auto pile:piles){
                currHr += ceil(1.0*pile/k);
            }
            hrs=min((int)currHr,hrs);
            if(h>=hrs) return k;
        }
        return -1;
    }
};