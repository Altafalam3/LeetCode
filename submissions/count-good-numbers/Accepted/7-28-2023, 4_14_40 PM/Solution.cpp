// https://leetcode.com/problems/count-good-numbers

#include <cmath>


class Solution {
public:
    int countGoodNumbers(long long n) {
        const long long mod = 1000000007;

        long long odd = n / 2;
        long long even = n - odd;

        long long eval = 5;
        long long oval = 4;

        long long ans = (powHelper(eval, even, mod) * powHelper(oval, odd, mod)) % mod; // Fix formula

        return ans;
    }

    long long powHelper(long long x, long long int n, long long mod) {
        if (n == 0) {
            return 1;
        }

        long long halfPow = powHelper(x, n / 2, mod) % mod;
        long long result = (halfPow * halfPow) % mod;

        if (n % 2 == 0) {
            return result;
        } else {
            return (result * x) % mod;
        }
    }
};


            