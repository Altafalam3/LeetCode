// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=1;
        ListNode* temp=head;
        while(temp->next!=nullptr){
            if(temp->next->next!=nullptr){
                count+=2;
                temp=temp->next->next;
            }
            else if(temp->next!=nullptr){
                count+=1;
                temp=temp->next;
            }
        }
        temp=head;
        int index= count-n;
        while(temp!=nullptr && index>0){
            if(index==1){
                temp->next=temp->next->next;
                return head;
            }
            else{
                temp=temp->next;
            }
            index--;
        }
        return nullptr;
    }
};