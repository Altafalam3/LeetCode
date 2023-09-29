// https://leetcode.com/problems/unique-paths

class Solution {
private:
    void uniquepaths(int m, int n,int i, int j, int& count) {
        if(i==(m-1)&&j==(n-1)){
            count+=1;
            return;
        }
        if(i>(m-1) || j>(n-1)){
            return;
        }

        uniquepaths(m, n, i+1, j, count);

        uniquepaths(m, n, i, j+1, count);
  
    }
public:
    int uniquePaths(int m, int n) {
        int i=0, j=0, count=0;
        uniquepaths(m, n, i, j, count);

        return count;
    }
};