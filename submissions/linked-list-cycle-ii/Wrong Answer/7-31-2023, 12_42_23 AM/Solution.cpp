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
      
      if(head==nullptr || head->next==nullptr) return nullptr;
        ListNode* slow=head, *fast=head->next->next;
      while(slow && fast){
          if(slow==fast){
            return slow;
            }
           else{
             slow=slow->next;
             fast=fast->next->next;
       }
    }
      return nullptr;
   }
};