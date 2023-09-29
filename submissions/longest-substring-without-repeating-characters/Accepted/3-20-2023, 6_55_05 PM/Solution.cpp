// https://leetcode.com/problems/longest-substring-without-repeating-characters

#include <iostream>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0,max_length=0;
        unordered_map<char, int> char_map;

        for(int i=0;i<s.size();i++){
            if (char_map.count(s[i]) && char_map[s[i]] >= start) {
                max_length = max(max_length, i - start);
                start = char_map[s[i]] + 1;
            }
            char_map[s[i]] = i;
        }
        return max(max_length,(int)s.size()-start);
    }
};