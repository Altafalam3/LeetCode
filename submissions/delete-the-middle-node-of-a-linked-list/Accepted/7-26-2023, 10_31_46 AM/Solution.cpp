// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
      if (head == nullptr ){
            return head;

        }
      else if(head->next==nullptr){
        delete head;
        return nullptr;
        }
        ListNode* slow=head,*fast=head,*slowprev=nullptr;
        
        while(fast!=nullptr && fast->next!=nullptr){
            slowprev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *nextt=slow->next;
      delete slow;
      
            slowprev->next=nextt;
      
        return head;
    }
};