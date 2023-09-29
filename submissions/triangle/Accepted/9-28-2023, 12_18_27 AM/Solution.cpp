// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return minTotal(0, 0, n, triangle, dp);
    }

private:
    int minTotal(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        // Base case: reach the bottom row, return value in triangle.
        if (i == n - 1) {
            return triangle[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // result for the curr position by two possible paths.
        int down1 = minTotal(i + 1, j, n, triangle, dp);
        int down2 = minTotal(i + 1, j + 1, n, triangle, dp);

        // Update dp with the min of two paths plus the current element.
        dp[i][j] = min(down1, down2) + triangle[i][j];

        return dp[i][j];
    }
};
