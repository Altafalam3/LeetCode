// https://leetcode.com/problems/rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;

        int count=1;

        ListNode* temp=head;

        while(temp->next!=nullptr){

            count++;

            temp=temp->next;

        }
        temp->next=head;

        int check= k%count;
        ListNode *newHead=nullptr;

        while(check!=0){
            head=head->next;
            check--;
        }
        newHead=head->next;
        head->next=nullptr;
        return newHead;
        
    }
};