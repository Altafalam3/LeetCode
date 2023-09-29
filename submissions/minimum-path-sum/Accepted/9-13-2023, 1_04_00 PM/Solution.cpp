// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp (n, vector<int>(m,-1));

        // base cases filling
        dp[0][0] = grid[0][0];

        for(int i=1; i< n; i++){
            dp[i][0]=grid[i][0] + dp[i-1][0];
        }

        for(int j=1; j< m; j++){
            dp[0][j]=grid[0][j] + dp[0][j-1];
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                int down = grid[i][j] + dp[i-1][j];
                int right= grid[i][j] + dp[i][j-1];
                dp[i][j] = min(down,right); 
            }
        }

        return dp[n-1][m-1];
    }

};