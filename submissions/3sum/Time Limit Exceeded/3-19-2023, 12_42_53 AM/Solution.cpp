// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> temp;
        vector<vector<int>> ans;
        int target=0;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            int j=i+1,k=nums.size()-1;
            while(j<k){
                vector <int> a1;
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==target){
                    a1.push_back(nums[i]);
                    a1.push_back(nums[j]);
                    a1.push_back(nums[k]);
                    j++;
                    k--;
                    temp.insert(a1);
                }
                else if(sum<target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        for(auto i:temp){
            ans.push_back(i); 
        }
        return ans;
    }
};