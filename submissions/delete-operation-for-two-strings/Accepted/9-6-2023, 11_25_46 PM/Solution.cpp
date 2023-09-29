// https://leetcode.com/problems/delete-operation-for-two-strings

class Solution {
public:
    int minDistance(string word1, string word2) {
        int longest = longestCommonSubsequence(word1, word2);
        return (word1.size() - longest + word2.size() - longest);
    }
private:
    int longestCommonSubsequence(string& text1, string& text2) {
        int n=text1.size(), m=text2.size();
        vector<int> prev(m+1, 0), curr(m+1);

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = max(prev[j],curr[j-1]);
                }        
            }
            prev=curr;
        }

        return prev[m];
    }

};