// https://leetcode.com/problems/rotate-string

class Solution {
public:
    bool rotateString(string s, string goal) {
        string ss = s+s;
        
        size_t found = ss.find(goal);
        if (found != string::npos)
            return true;

        return false;
    }
};