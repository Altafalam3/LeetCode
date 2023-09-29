// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        int freqCount[26] = {0};
        
        for (auto x : s) {
            freqCount[x - 'a']++;
        }
        
        for (auto x : t) {
            freqCount[x - 'a']--;
        }
        
        for (auto count : freqCount) {
            if (count != 0) {
                return false;
            }
        }
        
        return true;
    }
};