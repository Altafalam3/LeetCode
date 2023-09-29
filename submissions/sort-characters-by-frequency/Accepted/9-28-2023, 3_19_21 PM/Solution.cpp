// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        vector<int> charCount(256, 0); // Assuming ASCII characters

        // Count the frequency of each character
        for (char ch : s) {
            charCount[ch]++;
        }

        // Create a vector of pairs (character, frequency)
        vector<pair<char, int>> freqPairs;
        for (int i = 0; i < 256; i++) {
            if (charCount[i] > 0) {
                freqPairs.emplace_back(static_cast<char>(i), charCount[i]);
            }
        }

        // Sort the vector based on frequency in descending order
        sort(freqPairs.begin(), freqPairs.end(), sortByFrequency);

        // Build the result string
        string result = "";
        for (auto& pair : freqPairs) {
            result += string(pair.second, pair.first);
        }

        return result;
    }

private:
    static bool sortByFrequency(const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    }
};
