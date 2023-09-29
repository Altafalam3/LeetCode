// https://leetcode.com/problems/unique-paths

class Solution {
private:
    int uniquepaths(int m, int n, int i, int j, vector<vector<int>>& dp) {
        if (i == m - 1 && j == n - 1) {
            return 1; // Reached the destination.
        }
        if (i >= m || j >= n) {
            return 0; // Out of bounds.
        }
        if (dp[i][j] != -1) {
            return dp[i][j]; // Return memoized result.
        }

        int right = uniquepaths(m, n, i, j + 1, dp);
        int down = uniquepaths(m, n, i + 1, j, dp);

        // Store the result in the memoization table.
        dp[i][j] = right + down;
        return dp[i][j];
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1)); // Initialize memoization table.
        return uniquepaths(m, n, 0, 0, dp);
    }
};
