// https://leetcode.com/problems/middle-of-the-linked-list

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
    ListNode* middleNode(ListNode* head){
        ListNode* temp=head;
        int count=1;
        while(temp->next!=nullptr){
            count++;
            temp=temp->next;
        }
        int mid=(count/2)+1;
        temp=head;
        while(--mid){
            temp=temp->next;
        }
        return temp;
    }
}; 