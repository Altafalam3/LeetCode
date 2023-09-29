// https://leetcode.com/problems/reverse-string

class Solution {
public:
    void reversee(vector<char>& s,int l, int r) {
        if (l>=r) return;
        swap(s[l],s[r]);
        reversee(s,l+1,r-1);
    }
    
    void reverseString(vector<char>& s) {
        int r=s.size()-1,l=0;
        reversee(s,l,r);
        
    }
    
    
};