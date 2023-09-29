// https://leetcode.com/problems/search-a-2d-matrix

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, row = matrix.size();
        int col = matrix[0].size();

        for(int i=0; i < row;i++){
            if(matrix[i][0]<= target && matrix[i][col-1] >= target){
                return binary_search(matrix[i].begin(),matrix[i].end(),target);
            }
        }
        return false;
    }
};