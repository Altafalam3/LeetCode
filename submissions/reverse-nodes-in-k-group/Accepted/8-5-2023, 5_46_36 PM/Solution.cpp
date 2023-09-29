// https://leetcode.com/problems/reverse-nodes-in-k-group

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        for (ListNode* temp = head; temp != nullptr; temp = temp->next) {
            count++;
        }

        if (count < k) return head;

        ListNode* prevGroupTail = nullptr;
        ListNode* newHead = nullptr;
        
        while (count >= k) {
            ListNode* prev = nullptr;
            ListNode* curr = head;
            ListNode* next = nullptr;
            int ktemp = k;

            while (ktemp > 0) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
                ktemp--;
            }

            if (prevGroupTail != nullptr) {
                prevGroupTail->next = prev;
            } else {
                newHead = prev;
            }

            prevGroupTail = head;
            head = curr;
            count -= k;
        }
        
        if (prevGroupTail != nullptr) {
            prevGroupTail->next = head;
        } else {
            newHead = head;
        }

        return newHead;
    }
};
