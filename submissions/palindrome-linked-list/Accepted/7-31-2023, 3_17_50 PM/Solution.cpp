// https://leetcode.com/problems/palindrome-linked-list

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
    bool isPalindrome(ListNode* head) {
        ListNode* slow =head;
        ListNode* fast =head;
        ListNode*temp=nullptr;
        int count=0;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        temp=slow->next;
        if(fast->next!=nullptr){
            fast=fast->next;
        }
        //reverse from temp to fast
        ListNode *prev=nullptr,*nextt=temp;
        while(temp){
            nextt=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nextt;
        }
        slow->next=prev;
        slow=slow->next;
        while(slow){
          if(slow->val!=head->val){
              return false;
           }
           slow=slow->next;
           head=head->next;
         }
      return true;
    }
};