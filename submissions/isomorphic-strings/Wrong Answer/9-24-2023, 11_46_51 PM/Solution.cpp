// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,char> ch;

        for(int i=0; i<s.size();i++){
            char curr = s[i];

            if(ch.find(curr) == ch.end()){
                ch[curr] = t[i];
            }
            else if(ch[curr] != t[i] ){
                return false;
            }
        }
        return true;
    }
};