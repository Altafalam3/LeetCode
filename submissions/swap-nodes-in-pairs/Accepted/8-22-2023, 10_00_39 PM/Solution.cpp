// https://leetcode.com/problems/swap-nodes-in-pairs

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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* newHead = head->next;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = curr;
            if (prev) prev->next = nextNode;
            prev = curr;
            curr = curr->next;
        }

        return newHead;
    }
};
