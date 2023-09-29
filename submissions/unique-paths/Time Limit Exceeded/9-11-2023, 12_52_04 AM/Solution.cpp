// https://leetcode.com/problems/unique-paths

class Solution {
private:
    int uniquepaths(int m, int n, int i, int j) {
        if (i == m - 1 && j == n - 1) {
            return 1; // Reached the destination.
        }
        if (i >= m || j >= n) {
            return 0; // Out of bounds.
        }

        int right = uniquepaths(m, n, i, j + 1);
        int down = uniquepaths(m, n, i + 1, j);

        return right + down;
    }

public:
    int uniquePaths(int m, int n) {
        return uniquepaths(m, n, 0, 0);
    }
};
