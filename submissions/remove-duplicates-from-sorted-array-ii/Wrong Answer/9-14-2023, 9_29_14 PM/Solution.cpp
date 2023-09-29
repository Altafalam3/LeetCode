// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int currCount=1;
        for(int i=0;i < nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                if(currCount>=2){
                    nums[i]=-1;
                }
                else{
                    currCount++;
                }
            }
            else{
                currCount=1;
            }
        }

        int i=0, j=nums.size()-1;
        while(i<=j){
            if(nums[i]!=-1){
                i++;
            }
            else if(nums[j]==-1){
                j--;
            }
            else{
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }
        sort(nums.begin(),nums.begin()+i);
        return i;
    }
};