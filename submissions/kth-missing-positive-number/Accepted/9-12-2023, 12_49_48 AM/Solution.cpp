// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missingCount = 0;
        int num = 1;
        int index = 0;

        while (missingCount < k) {
            if (index < arr.size() && arr[index] == num) {
                // Found a number from the array, move to the next index
                index++;
            } else {
                missingCount++;
                if (missingCount == k) {
                    return num;
                }
            }
            num++;
        }

        // Handle the case when k exceeds the range of missing numbers
        return num + k - missingCount - 1;
    }
};
