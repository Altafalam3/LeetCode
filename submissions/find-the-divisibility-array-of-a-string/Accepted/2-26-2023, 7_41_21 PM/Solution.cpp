// https://leetcode.com/problems/find-the-divisibility-array-of-a-string

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int>ans;
        long long prevRem = 0;
        for (int i = 0; i < word.size(); i++)
        {
            int currDig = word[i] - '0';
			//newDividend = currDig appended to previous remainder
            long long newDividend = (prevRem * 10) + currDig;  
            
            int rem = (newDividend % m);
            if (rem == 0) ans.push_back(1);
            else ans.push_back(0);
            
            prevRem = rem; 
        }
        return ans;   
    }
};