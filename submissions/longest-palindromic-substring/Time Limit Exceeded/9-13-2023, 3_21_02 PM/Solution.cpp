// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<string> substring;
        for(int i=0; i<n; i++){
            string temp = "";
            for(int j=i; j<n; j++){
                temp += s[j];
                substring.push_back(temp);
            }
        }

        int max_len = 0;
        string finalans = substring[0];
        int m = substring.size();
        
        for(int i=0; i<m; i++){
            int s = substring[i].size();
            if(isPalindrome(substring[i], 0, s-1)){
                if(s > max_len){
                    max_len = s;
                    finalans = substring[i];
                }
            }       
        }
        return finalans;
    }

private:
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
