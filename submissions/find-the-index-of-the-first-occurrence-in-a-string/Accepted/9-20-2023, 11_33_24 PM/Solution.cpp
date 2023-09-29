// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }

        // longest proper prefix
        vector<int> lps = computeLPS(needle);

        int i = 0; // Index for haystack
        int j = 0; // Index for needle

        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == needle.size()) {
                return i - j; // Found a match
            }

            if (i < haystack.size() && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return -1; // Needle not found in haystack
    }

private:
    vector<int> computeLPS(const string& needle) {
        int length = 0; // Length of the previous longest prefix suffix

        vector<int> lps(needle.size(), 0);

        int i = 1;
        while (i < needle.size()) {
            if (needle[i] == needle[length]) {
                length++;
                lps[i] = length;
                i++;
            } 
            else {
                if (length != 0) {
                    length = lps[length - 1];
                } 
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }
};
