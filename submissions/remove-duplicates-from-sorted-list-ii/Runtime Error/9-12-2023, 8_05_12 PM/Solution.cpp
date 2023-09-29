// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

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
        ListNode *curr=head, *nextt=nullptr, *prev=nullptr;

        if(!head || !head->next) return head;

        while(curr && curr->next){
            nextt=curr->next;
            //find start and end pt jaha tak repeat ho rha
            if(curr->val == nextt->val){
                while(curr->val == nextt->val){
                    nextt=nextt->next;
                }

                // non first node prev exist
                if(prev!=nullptr){
                    prev->next=nextt;
                    curr=nextt;
                }
                // 1st node se ... x nodes tak dulicates h
                else{
                    curr=nextt;
                    head=nextt;
                }
            }
            // prev and curr changes 
            else{
                prev=curr;
                curr=curr->next;
            }
        }

        return head;
    }
};