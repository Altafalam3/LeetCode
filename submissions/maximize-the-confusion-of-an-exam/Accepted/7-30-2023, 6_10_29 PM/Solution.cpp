// https://leetcode.com/problems/maximize-the-confusion-of-an-exam

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int longest1=maxAns(answerKey,k,'T');
        int longest2=maxAns(answerKey,k,'F');

        return max(longest1,longest2);

    }

    int maxAns(string answerKey, int k,char check){
        int start=0,end=0,longest=0;
        int curr=0;

        while(end<answerKey.size()){
            if(answerKey[end]==check){
                curr++;
            }
            if(curr>k){
                if(answerKey[start]==check){
                    curr--;
                }
                start++;
            }
            longest=max(longest,end-start+1);
            end++;
        }
        return longest;

    }
};