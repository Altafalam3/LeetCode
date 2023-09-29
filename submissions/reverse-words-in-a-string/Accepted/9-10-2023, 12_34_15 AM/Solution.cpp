// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, ans;

        // stringstream along with a loop to split a string into words based on a delimiter
        while(ss >> word){
            ans = word + " " + ans;
        }
        
        return ans.substr(0, ans.size()-1);;     

    }
};