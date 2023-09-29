// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> um;

        // Count the frequency of each character
        for (char ch : s) {
            um[ch]++;
        }

        // Create a vector of pairs (character, frequency)
        vector<pair<char, int>> freqPairs;
        for (auto m : um) {
            freqPairs.push_back(m);
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
