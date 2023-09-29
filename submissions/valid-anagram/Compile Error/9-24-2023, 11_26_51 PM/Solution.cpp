// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> freqCount;

        for(auto i:s){
            freqCount[i]++;
        }

        for(auto i:t){
            freqCount[i]--;
        }

        for(auto i:freqCount){
            if(x.second!=0){
                return false;
            }
        }
        return true;
    }
};