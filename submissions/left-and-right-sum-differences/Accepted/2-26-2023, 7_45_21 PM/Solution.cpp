// https://leetcode.com/problems/left-and-right-sum-differences

class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> left;
        vector<int> right;
        int sum1=0,sum2=0;
        
        for(int i=0;i<nums.size();i++){
            
            if(i>0){
                sum1 += nums[i-1];
                left.push_back(sum1);
            }
            else{
                left.push_back(sum1);
            }
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            
            if(i==nums.size()-1){
                right.push_back(sum2);
            }
            else{
                sum2 += nums[i+1];
                right.push_back(sum2);
            }
        }
        
        for(int i=0;i<nums.size();i++){
            int a=abs(left[i]-right[nums.size()-1-i]);
            left[i]=a;
        }
        
        return left;
    }
};