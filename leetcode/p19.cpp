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
    int a;
    void recurse(ListNode* head, int& n) {
        if (head == NULL) return;
        recurse(head->next,n);
        if (a == n) head->next = head->next->next;
        a++;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        a = 0;
        if (head->next == NULL) return head->next;
        recurse(head, n);
        if (a==n) return head->next;
        return head;
    }
};