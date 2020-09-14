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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* prev = head;
        head = head->next;
        ListNode* nex = head->next;
        prev->next = NULL;
        while (nex != NULL) {
            head->next = prev;
            prev = head;
            head = nex;
            nex = head->next;
        }
        head->next = prev;
        return head;
    }
};