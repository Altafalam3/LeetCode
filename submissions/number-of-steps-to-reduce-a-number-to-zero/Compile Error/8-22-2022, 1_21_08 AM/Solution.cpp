// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero

class Solution {
public:
    int numberOfSteps(int num) {
count=0;
        if(num==0){
          return count;
        }
        else if (num%2==0 ){
          
          count++;
          return numberOfSteps(num/2);
          }
          
          count++;
          return numberOfSteps(num-1);
          
     // return count;
    }class Solution {
public:
    int numberOfSteps(int num) {
	if(num==0)
	{
		return 0;
	}
        
        if(num%2==0)
        	return 1+numberOfSteps(num/2);
        return 1+numberOfSteps(num-1);

}
};