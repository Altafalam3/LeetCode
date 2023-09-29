// https://leetcode.com/problems/divide-two-integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle special cases
        if (divisor == 0) {
            return (dividend > 0) ? INT_MAX : INT_MIN;
        }
        if (dividend == 0) {
            return 0;
        }

        // Determine the sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Take the absolute values of dividend and divisor
        long long abs_dividend = llabs(static_cast<long long>(dividend));
        long long abs_divisor = llabs(static_cast<long long>(divisor));

        long long quotient = 0;
        while (abs_dividend >= abs_divisor) {
            long long temp = abs_divisor;
            long long multiple = 1;
            while (abs_dividend >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            abs_dividend -= temp;
            quotient += multiple;
        }

        // Apply sign to the result
        if (negative) {
            quotient = -quotient;
        }

        // Handle overflow cases
        if (quotient > INT_MAX) {
            return INT_MAX;
        }
        if (quotient < INT_MIN) {
            return INT_MIN;
        }

        return static_cast<int>(quotient);
    }
};
