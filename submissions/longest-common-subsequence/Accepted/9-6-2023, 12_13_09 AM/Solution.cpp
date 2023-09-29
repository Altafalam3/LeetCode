// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(), m=text2.size();
        vector <vector<int>> dp(n,vector<int>(m, -1));

        return longest(text1, text2, 0, 0, dp);
    }

private:
    int longest(string &text1, string &text2, int i, int j, vector<vector<int>>& dp){
        if(i==text1.size() || j==text2.size()){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i]==text2[j]){
            return dp[i][j] = 1 + longest(text1, text2, i+1, j+1, dp);
        }
        else{
            int firstShift = longest(text1, text2, i+1, j, dp);
            int secondShift = longest(text1, text2, i, j+1, dp);
            return dp[i][j] = max(firstShift,secondShift);
        }
    }
};