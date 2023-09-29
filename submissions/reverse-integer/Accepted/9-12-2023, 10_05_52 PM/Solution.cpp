// https://leetcode.com/problems/reverse-integer

#include <bits/stdc++.h>
class Solution {
public:
    int reverse(int x) {
        // Convert the integer to a string
        string num = to_string(x);

        // Check if the number is negative
        if (x < 0) {
            // Reverse the string, excluding negative sign
            reverseStr(num, 1, num.size()-1);
        } else {
            // Reverse the entire string
            reverseStr(num, 0, num.size()-1);
        }

        long long result = stoll(num); // Convert the string back to a long long
        if (result < INT_MIN || result > INT_MAX) {
            return 0; // Overflow, return 0
        }

        return (int)(result);
    }

    void reverseStr(string& str, int i, int n)
    {
        while(i<=n){
            swap(str[i],str[n]);
            n = n-1;
            i = i+1;
        }
    }

};
