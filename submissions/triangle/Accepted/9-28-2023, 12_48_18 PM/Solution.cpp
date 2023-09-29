// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n, INT_MAX), curr(n, INT_MAX);

        for(int i=0; i< n; i++){
            for(int j=0; j<=i; j++){
                // base case
                if(i==0 && j==0){
                    curr[j] = triangle[i][j];
                }

                else{
                    int take1 = prev[j];
                    int take2 = (j - 1 >= 0) ? prev[j - 1] : INT_MAX;
                    curr[j] = min(take1, take2) + triangle[i][j];
                }
            }
            prev = curr;
        }

        int result = INT_MAX;
        for (int j = 0; j < n; j++) {
            result = min(result, prev[j]);
        }

        return result;
    }
};
