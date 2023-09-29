// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
        int reversed = 0;

        while (x != 0) {
            int rem = x % 10;

            // Check for integer overflow before updating the result
            if (reversed > INT_MAX / 10.0 ) {
                return 0;
            }
            if (reversed < INT_MIN / 10.0) {
                return 0;
            }

            reversed = reversed * 10 + rem;
            x /= 10;
        }

        return reversed;
    }
};
