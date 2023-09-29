// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int i=0,j=0;

        return uniquePathsWithObstacle(obstacleGrid, m, n, i, j);

    }

private:
    int uniquePathsWithObstacle(vector<vector<int>>& obstacleGrid, int m, int n, int i, int j) {
        // reached destination
        if(i==(m-1)&&j==(n-1)){
            return 1;
        }

        // out of bounds
        if(i>(m-1) || j>(n-1)){
            return 0;
        }

        // obstacle found
        if(obstacleGrid[i][j]==1){
            return 0;
        }

        int down = uniquePathsWithObstacle(obstacleGrid, m, n, i+1, j);
        int right = uniquePathsWithObstacle(obstacleGrid, m, n, i, j+1);

        return right + down;
    }
};