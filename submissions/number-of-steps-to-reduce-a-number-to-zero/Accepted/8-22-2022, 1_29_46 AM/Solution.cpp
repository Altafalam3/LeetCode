// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero

class Solution {
public:
    int numberOfSteps(int num) {
	if(num==0)
	{
		return 0;
	}
        
       else if(num%2==0)
        	return 1+numberOfSteps(num/2);
      
   else return 1+numberOfSteps(num-1);

}
};