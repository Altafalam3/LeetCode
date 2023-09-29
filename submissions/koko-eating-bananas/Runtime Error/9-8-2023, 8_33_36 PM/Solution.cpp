// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBanana=0;
        for(auto pile:piles){
            maxBanana = max(maxBanana, pile);
        }

        int left = 1;
        int right = maxBanana;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int currHr = 0;

            for (auto pile : piles) {
                currHr += ceil(1.0 * pile / mid);
            }

            if (currHr <= h) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};