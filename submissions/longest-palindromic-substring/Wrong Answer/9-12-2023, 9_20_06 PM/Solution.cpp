// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string longest = "";

        generateSubstrings(s, 0, "", longest);

        return longest;
    }

private:
    void generateSubstrings(string& s, int index, string current, string& longest) {
        if (index == s.size()) {
            if (isPalindrome(current) && current.size() > longest.size()) {
                longest = current;
            }
            return;
        }

        // Include the current character in the substring
        generateSubstrings(s, index + 1, current + s[index], longest);

        // Exclude the current character from the substring
        generateSubstrings(s, index + 1, current, longest);
    }

    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
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
