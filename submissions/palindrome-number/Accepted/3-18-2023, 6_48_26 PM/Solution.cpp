// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        string y=to_string(x);
        int n=y.size();
        if(x<0)return false;
        for(int i=0;i<n/2;i++){
            if(y[i]!=y[n-1-i]){
                return false;
            }
        }
        return true;
    }
};