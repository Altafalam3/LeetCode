// https://leetcode.com/problems/triangle

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int i=0,j=0,n=triangle.size(),nlevel=0,sum=0;

        int ans = minTotal(i,j,n,nlevel,sum,triangle);
        return ans;
    }

private:
    int minTotal(int i, int j, int n, int nlevel, int sum, vector<vector<int>>& triangle){
        if(i==n){
            return sum;
        }

        sum+=triangle[i][j];
        int take1 = minTotal(i+1, j, n, nlevel+1, sum, triangle);

        sum-=triangle[i][j];

        if((j+1) <=nlevel){
            sum+=triangle[i][j+1];
            int take2 = minTotal(i+1, j+1, n, nlevel+1, sum, triangle);

            return min(take1, take2);
        }

        return take1;
    }
};