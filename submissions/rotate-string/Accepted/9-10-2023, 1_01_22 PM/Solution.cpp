// https://leetcode.com/problems/rotate-string

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;

        int n=s.size(), count=0;
        
        for(int i = 0; i < s.length(); i++) {
            if(rotatedString(s, goal, i)) {
                return true;
            }
        }

        return false;
    }

private: 
    bool rotatedString(string A, string B, int rotation) {
        for(int i = 0; i < A.length(); i++) {
            if(A[i] != B[(i+rotation) % B.length()]) {
                return false;
            }
        }
        return true;
    }
    
};