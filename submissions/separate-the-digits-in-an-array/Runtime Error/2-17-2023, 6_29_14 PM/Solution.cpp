// https://leetcode.com/problems/separate-the-digits-in-an-array

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums){
        vector <int> ans;
        for(auto &i:nums){
            if(i<10){
                ans.push_back(i);
            }
            else{
                int temp2=i,count=0;
                vector <int>temp;
                while(temp2!=0){
                    temp.push_back(temp2%10);
                    temp2/=10;
                    count++;
                }
                
                for(int i=count;i>=0;i++){
                    ans.push_back(temp[i]);
                }
                
            }
        }
        return ans;
    }
};