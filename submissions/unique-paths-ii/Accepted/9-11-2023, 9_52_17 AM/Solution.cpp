// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int i=0,j=0;

        vector<vector<int>> dp(m, vector<int>(n,-1));

        return uniquePathsWithObstacle(obstacleGrid, m, n, i, j, dp);

    }

private:
    int uniquePathsWithObstacle(vector<vector<int>>& obstacleGrid, int m, int n, int i, int j, vector<vector<int>>& dp) {

        // out of bounds
        if(i>(m-1) || j>(n-1)){
            return 0;
        }

        // obstacle found
        if(obstacleGrid[i][j]==1){
            return 0;
        }

        // reached destination
        if(i==(m-1)&&j==(n-1)){
            return 1;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int down = uniquePathsWithObstacle(obstacleGrid, m, n, i+1, j, dp);
        int right = uniquePathsWithObstacle(obstacleGrid, m, n, i, j+1, dp);

        dp[i][j] = right + down;
        return dp[i][j];
    }
};