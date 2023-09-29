// https://leetcode.com/problems/longest-common-prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1; i<strs.size(); i++){
            string curr= strs[i];

            int j=0;
            for(j=0;j<curr.size();j++){
                if(ans[j]!=curr[j]){
                    break;
                }
            }

            ans = ans.substr(0, j);
        }
        return ans;
    }
};