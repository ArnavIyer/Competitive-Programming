/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return head;
        ListNode* curr = head;
        ListNode* next = head->next;
        ListNode* newhead = head->next;
        ListNode* prev;
        
        if (head->next == NULL) return head;
        if (head->next->next == NULL) {
            next->next = curr;
            curr->next = NULL;
            return next;
        }
        int ct = 0;
        while (curr->next != NULL) {
            if (ct == 1) prev = newhead->next;
            curr->next = next->next;
            next->next = curr;
            if (ct > 0) {
                prev->next = next;
            }
            if (curr->next == NULL || curr->next->next == NULL) break;
            else {
                prev = curr;
                curr = curr->next;
                next = curr->next;
            }
            ct++;
        }
        return newhead;
    }
};