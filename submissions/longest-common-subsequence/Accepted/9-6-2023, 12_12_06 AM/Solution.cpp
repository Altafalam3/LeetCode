// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(), m=text2.size();
        vector <vector<int>> dp(n + 1,vector<int>(m + 1, -1));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        return longest(text1, text2, 0, 0, dp);
    }

private:
    int longest(string &text1, string &text2, int i, int j, vector<vector<int>>& dp){
        if(i==text1.size() || j==text2.size()){
            return 0;
        }
        if(dp[i+1][j+1] != -1) return dp[i+1][j+1];

        if(text1[i]==text2[j]){
            return dp[i+1][j+1] = 1 + longest(text1, text2, i+1, j+1, dp);
        }
        else{
            int firstShift = longest(text1, text2, i+1, j, dp);
            int secondShift = longest(text1, text2, i, j+1, dp);
            return dp[i+1][j+1] = max(firstShift,secondShift);
        }
    }
};