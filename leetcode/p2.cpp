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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head;
        ListNode* curr = new ListNode(0);
        bool list1 = true;
        bool list2 = true;
        head = curr;
        int carry = 0;
        int lcarry = 0;
        while (list1 || list2) {
            int nume = 0;
            if (list1) nume += l1->val;
            if (list2) nume += l2->val;
            nume += lcarry;
            carry = nume/10;
            nume = nume%10;
            curr->next = new ListNode(nume);
            lcarry = carry;
            curr = curr->next;
            if (list1) l1=l1->next;
            if (list2) l2=l2->next;
            if (l1 == NULL) list1 = false;
            if (l2 == NULL) list2 = false;
        }
        if (lcarry > 0) {
            curr->next = new ListNode(1);
        }
        return head->next;
    }
};