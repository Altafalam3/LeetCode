// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> prev(m, 0), curr(m, 0);

        // Base case filling
        prev[0] = grid[0][0];

        // Fill the first row
        for (int j = 1; j < m; j++) {
            prev[j] = grid[0][j] + prev[j - 1];
        }

        for (int i = 1; i < n; i++) {
            // Initialize the first element of curr for each row
            curr[0] = grid[i][0] + prev[0];
            for (int j = 1; j < m; j++) {
                int down = grid[i][j] + prev[j];
                int right = grid[i][j] + curr[j - 1];
                curr[j] = min(down, right);
            }
            // Copy curr to prev for the next row
            prev = curr;
        }

        return prev[m - 1];
    }
};
