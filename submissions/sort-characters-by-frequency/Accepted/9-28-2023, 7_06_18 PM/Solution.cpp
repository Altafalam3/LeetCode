// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        vector<int> charCount(256, 0); // Assuming ASCII characters
        int maxFreq = 0;

        // Count the frequency of each character and find the maximum frequency
        for (char ch : s) {
            charCount[ch]++;
            maxFreq = max(maxFreq, charCount[ch]);
        }

        // vector of buckets to store chars with same frequency from 1 to maxfreq
        vector<vector<char>> buckets(maxFreq + 1);

        // Place characters into buckets based on their frequency
        for (int i = 0; i < 256; i++) {
            if (charCount[i] > 0) {
                buckets[charCount[i]].push_back(static_cast<char>(i));
            }
        }

        // result by iterating over buckets in descending frequency
        string result = "";
        for (int freq = maxFreq; freq > 0; freq--) {
            for (char ch : buckets[freq]) {
                result += string(freq, ch);
            }
        }

        return result;
    }
};
