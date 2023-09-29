// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1; i<strs.size(); i++){
            string curr= strs[i];
            string newsubstr = "";
            for(int j=0;j<curr.size();j++){
                if(ans[j]==curr[j]){
                    newsubstr += curr[j];
                }
                else if(!ans[j] || ans[j]!=curr[j]){
                    ans = newsubstr;
                    break;
                }
            }
            if(curr.size()<ans.size()){
                ans=newsubstr;
            }
            
        }
        return ans;
    }
};