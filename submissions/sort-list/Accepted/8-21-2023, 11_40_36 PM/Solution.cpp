// https://leetcode.com/problems/sort-list

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
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        while (left && right) {
            if (left->val < right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }
        
        if (left) {
            current->next = left;
        }
        
        if (right) {
            current->next = right;
        }
        current = dummy->next;
        delete(dummy);
        return current;
    }
    
    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* slow = head, *slowPrev = nullptr;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slowPrev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slowPrev->next = nullptr;
        ListNode* left = head;
        ListNode* right = slow;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        return merge(left, right);
    }
    
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
