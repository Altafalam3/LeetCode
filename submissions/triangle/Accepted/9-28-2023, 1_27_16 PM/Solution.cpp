// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> curr(n, INT_MAX), next(n, INT_MAX);
        // we are starting from last row to first row
        // so that we avoid traversing last row again for min

        for(int i=n-1; i>=0; i--){
            for(int j=0; j<=i; j++){
                // base case , last row
                if(i==n-1){
                    curr[j] = triangle[i][j];
                }

                else{
                    int take1 = next[j];
                    
                    int take2 = (j <= i) ? next[j + 1] : INT_MAX;
                    curr[j] = min(take1, take2) + triangle[i][j];
                }
            }
            next = curr;
        }

        return next[0];
    }
};