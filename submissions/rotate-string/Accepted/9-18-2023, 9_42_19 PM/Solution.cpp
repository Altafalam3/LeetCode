// https://leetcode.com/problems/rotate-string

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        // 2n same s twice
        s +=s;
        
        size_t found = s.find(goal);
        if (found != string::npos)
            return true;

        return false;
    }
};