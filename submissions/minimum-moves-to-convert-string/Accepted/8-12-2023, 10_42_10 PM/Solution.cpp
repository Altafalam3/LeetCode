// https://leetcode.com/problems/minimum-moves-to-convert-string

class Solution {
public:
    int minimumMoves(string s) {
        int i = 0, n = s.length(), count = 0;
	    while (i < n) {
		    if (s[i] == 'X'){
                count++,
                i += 3;
            }
		    else{
			    i++;
            }
	    }
	    return count;
    }
};