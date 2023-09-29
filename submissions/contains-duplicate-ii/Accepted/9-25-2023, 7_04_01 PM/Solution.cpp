// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // map for storing the current window elements
        unordered_map<int,int> nmap;

        int n = nums.size();
        int i=0,j=0;

        // at first, filling the 1st window
        while(j<=k && j<n){
            int num = nums[j];

            if(nmap.find(num) != nmap.end()){
                return true;
            }
            nmap[num]++;

            j++;
        }

        // now shifting window size +1 with i,j
        // also erasing the old i value which is not currently in window
        nmap.erase(nums[i]);
        i++;

        while(j < n){
            int num = nums[j];
            
            // check if it in window or not and adding new element in window
            if(nmap.find(num) != nmap.end()){
                return true;
            }
            nmap[num]++;

            // erase of old window and shift
            int num2=nums[i];
            nmap.erase(num2);
            i++;
            j++;
        }
        return false;
    }
};