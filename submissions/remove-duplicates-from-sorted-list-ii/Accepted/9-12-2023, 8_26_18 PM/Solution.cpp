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
        ListNode *curr = head, *nextt = nullptr, *prev = nullptr;

        if (!head || !head->next) return head;

        while (curr && curr->next) {
            nextt = curr->next;
            // check if there is a chance of repetition
            if (curr->val == nextt->val) {
                // start is curr, and nextt will be the maximum repeated ka next node
                // handle the case when nextt is null then value giving 101 out of range
                while (curr->val == (nextt ? nextt->val : 101)) {
                    ListNode* temp = nextt;
                    nextt = nextt->next;
                    delete temp; // Delete the node with duplicate value
                }

                // prev isn't there since repetition starts from the 1st node
                if (prev != nullptr) {
                    prev->next = nextt;
                    delete curr; // Delete the current node
                    curr = nextt;
                }
                // 1st node se ... x nodes tak dulicates h
                else {
                    ListNode* temp = head;
                    head = nextt;
                    delete temp; // Delete the head node
                    curr = nextt;
                }
            }
            // prev and curr changes
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};
