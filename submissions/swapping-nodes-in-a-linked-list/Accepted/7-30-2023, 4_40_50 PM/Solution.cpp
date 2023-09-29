// https://leetcode.com/problems/swapping-nodes-in-a-linked-list

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode*n1=nullptr;
        int count=0;

        while(temp){
            count++;
            if(count==k){
                n1=temp;
            }
            temp=temp->next;
        }

        int i=1;
        for(temp=head;i!=(count-k+1);temp=temp->next){
            i++;
        }

        swap(n1->val,temp->val);
        
        return head;
    }
};