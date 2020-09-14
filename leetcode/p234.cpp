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
    ListNode* newHead;
    ListNode* newCurr;
    void len(ListNode* a, ListNode* prev) {
        if (a==NULL) {
            newHead = new ListNode(prev->val);
            newCurr = newHead;
            return;
        }
        len(a->next, prev->next);
        newCurr->next = new ListNode(prev->val);
        newCurr = newCurr->next;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        len(head->next, head);
        while (head != NULL) {
            if (head->val != newHead->val) return false;
            head = head->next;
            newHead = newHead->next;
        }
        return true;
    }
};