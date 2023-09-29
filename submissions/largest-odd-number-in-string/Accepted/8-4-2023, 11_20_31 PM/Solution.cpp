// https://leetcode.com/problems/largest-odd-number-in-string

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length() ;

        for ( int i = n - 1 ; i >= 0 ; i--){

            int number = num[i] - '0' ;

            if ( number&1 ) {

                return num.substr( 0 , i + 1 ) ;

            }

        }

        return "" ;

    
    }
};