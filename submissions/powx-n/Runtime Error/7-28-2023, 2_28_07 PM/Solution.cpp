// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {

            return 1.0;

        }

        if (n < 0) {

            x = 1 / x;

            n = -n;

        }



        return powHelper(x, n);
    }
  double powHelper(double x, long long n) {

        if (n == 1) {

            return x;

        }

        double halfPow = powHelper(x, n / 2);

        return (n % 2 == 0) ? halfPow * halfPow : halfPow * halfPow * x;

    }
};