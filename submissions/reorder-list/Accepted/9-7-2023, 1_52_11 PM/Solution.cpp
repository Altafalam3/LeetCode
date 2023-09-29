// https://leetcode.com/problems/reorder-list

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
    void reorderList(ListNode* head) {
        if(!head || !head->next){
            return;
        }

        ListNode *slow=head, *fast=head;
        // finding mid, if even length leftmost mid we get
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }

        // Reverse After mid terms and dont link it to first half

        ListNode *prev=slow, *curr=slow->next, *nextt=nullptr;
        prev->next=nullptr;
        while(curr){
            nextt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextt;
        }


        // Merge the two halves
        ListNode *first = head, *second = prev;
        ListNode *firstNext, *secondNext;
        while (first && second) {
            firstNext = first->next;
            secondNext = second->next;
            
            first->next = second;
            second->next = firstNext;
            
            first = firstNext;
            second = secondNext;
        }

    }
};