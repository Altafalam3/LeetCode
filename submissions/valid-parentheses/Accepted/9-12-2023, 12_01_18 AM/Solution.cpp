// https://leetcode.com/problems/valid-parentheses

#include <stack>
#include <string>

class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                parentheses.push(c);
            } else {
                if (parentheses.empty()) {
                    return false; // Closing parenthesis with no matching open parenthesis
                }

                char top = parentheses.top();
                parentheses.pop();

                if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))               {
                    return false; // Mismatched parentheses
                }
            }
        }

        return parentheses.empty(); // Check if there are any remaining open parentheses
    }
};
