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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr = headA;
        int alen = 0;
        while (curr != NULL) {
            curr = curr->next;
            alen++;
        }
        
        int blen = 0;
        curr = headB;
        while (curr != NULL) {
            curr = curr->next;
            blen++;
        }
        ListNode* big, *small;
        if (alen>blen) {
            big = headA; 
            small = headB;
        } else {
            big = headB; 
            small = headA;
        }
        for (int i = 0; i<abs(alen-blen); i++) big = big->next;
        
        while (big != NULL and small != NULL) {
            if (big == small) return big;
            big = big->next;
            small = small->next;
        }
        return NULL;
    }
};