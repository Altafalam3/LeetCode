// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // map for storing the indez
        unordered_map<int,int> nmap;

        int n = nums.size();
        int j=0;

        while(j < n){
            int num = nums[j];
            
            auto findd = nmap.find(num);
            // check if it in window or not and satisfy condn
            if(findd != nmap.end() && ((j - findd -> second) <= k)){
                return true;
            }
            nmap[num]=j;

            j++;
        }
        return false;
    }
};