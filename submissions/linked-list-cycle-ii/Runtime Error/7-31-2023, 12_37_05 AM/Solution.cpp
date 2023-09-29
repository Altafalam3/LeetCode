// https://leetcode.com/problems/linked-list-cycle-ii

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head, *fast=head->next->next;
      while(slow && fast){
          if(slow==fast){
            break;
            }
           else{
             slow=slow->next;
             fast=fast->next->next;
       }
    }
      return slow;
   }
};