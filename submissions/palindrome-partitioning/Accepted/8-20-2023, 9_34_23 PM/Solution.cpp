// https://leetcode.com/problems/palindrome-partitioning

class Solution {
public:
    int isPalindrome(string st,int l, int r){
        while (l < r) {
            if(st[l]!=st[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void palindromePartition(int ind,const string s, vector<string>& currentPath, vector<vector<string>>& result){
        if(ind == s.size()){
            result.push_back(currentPath);
            return;
        }

        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                currentPath.push_back(s.substr(ind, i-ind+1));
                palindromePartition(i+1, s, currentPath, result);
                currentPath.pop_back();
            }
        }      
    }

    vector<vector<string>> partition(string s) {
        vector<string>currentPath;
        vector<vector<string>> result;
        palindromePartition(0, s, currentPath, result);
        return result;
    }
};