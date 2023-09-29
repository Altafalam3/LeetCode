// https://leetcode.com/problems/remove-duplicates-from-sorted-list

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *curr=head, *nextt=nullptr;

        while(curr->next){
            nextt= curr->next;

            if(curr->val == nextt->val){
                curr->next=nextt->next;
                delete nextt;
            }
            else{
                curr=curr->next;
            }
        }
        return head;
    }
};