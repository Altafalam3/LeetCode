// https://leetcode.com/problems/remove-outermost-parentheses

class Solution {
public:
    string removeOuterParentheses(string s) {
      string ans;
      int st=0,ind=0;
      int n=s.size();
      for(int i=0;i<n;i++)
      {
         if(s[i]=='('){
           if(st==0){
             ind=i;
             }
           st++;
         }
         else if(s[i]==')'){
           st--;
           if(st==0){
             s.erase(ind,1);
             i--;
             s.erase(i,1);
             i--;
             n-=2;

           }
             
         }
         
      }
      return s;

    }
};