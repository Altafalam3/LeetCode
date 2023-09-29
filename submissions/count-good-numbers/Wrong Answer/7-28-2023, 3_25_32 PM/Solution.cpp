// https://leetcode.com/problems/count-good-numbers

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long mod = 100000007;

long long odd= n/2;

long long even=n-odd;
long long eval=5;

long long oval=4;
long long ans = (even*eval + odd*oval)%mod;

return ans;
    }
};