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
            // check if there is chance of repeated
            if(curr->val == nextt->val){
                // start is curr and nextt will be max repeated  ka next node
                // handle case when nextt is null then value giving -1 
                while(curr->val == (nextt ? nextt->val : -1)){
                    nextt=nextt->next;
                }

                // prev isnt there since repeat start from 1st node
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