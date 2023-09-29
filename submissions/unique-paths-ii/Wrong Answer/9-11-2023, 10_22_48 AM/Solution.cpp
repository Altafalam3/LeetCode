// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int i=0,j=0;

        vector<int> prev(n, 0), curr(n);

        // Initialize the curr 1st cell
        curr[0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

        // left most cell initialize 
        prev[0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

        // Initialize the first column based on the value of prev[0]
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 0){
                // compare with above rows value
                prev[i] = prev[i-1];
            }
        }


        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j]==0){
                    curr[j] = prev[j] + curr[j-1];
                }
            }
            prev=curr;
        }

        return prev[n-1];

    }

};