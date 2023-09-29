// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return longest(text1, text2, 0, 0);
    }

private:
    int longest(string text1, string text2, int i, int j){
        if(i==text1.size() || j==text2.size()){
            return 0;
        }

        if(text1[i]==text2[j]){
            return 1 + longest(text1, text2, i+1, j+1);
        }
        else{
            int firstShift = longest(text1, text2, i+1, j);
            int secondShift = longest(text1, text2, i, j+1);
            return max(firstShift,secondShift);
        }
    }
};