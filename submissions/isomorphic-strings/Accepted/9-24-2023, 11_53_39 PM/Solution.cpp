// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> smap;
        unordered_map<char, char> tmap;

        for (int i = 0; i < s.size(); i++) {
            char s_char = s[i];
            char t_char = t[i];

            if (smap.find(s_char) == smap.end() && tmap.find(t_char) == tmap.end()) {
                smap[s_char] = t_char;
                tmap[t_char] = s_char;
            }
            else if (smap[s_char] != t_char || tmap[t_char] != s_char) {
                return false;
            }
        }
        return true;
    }
};
