// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& chars) {
        int writeIndex = 0;  // Index for writing compressed characters
        int count = 1;       // Count of consecutive characters
        int n = chars.size();

        for (int i = 1; i < n; i++) {
            if (chars[i] == chars[i - 1]) {
                count++; // Increment count for consecutive characters
            } else {
                chars[writeIndex++] = chars[i - 1]; // Write the current character

                if (count > 1) {
                    // If count is greater than 1, write it as characters
                    string countStr = to_string(count);
                    for (char c : countStr) {
                        chars[writeIndex++] = c;
                    }
                }

                count = 1; // Reset the count for the new character
            }
        }

        // Write the last character and its count
        chars[writeIndex++] = chars[n - 1];
        if (count > 1) {
            string countStr = to_string(count);
            for (char c : countStr) {
                chars[writeIndex++] = c;
            }
        }

        return writeIndex; // length of compressed sequence
    }
};
