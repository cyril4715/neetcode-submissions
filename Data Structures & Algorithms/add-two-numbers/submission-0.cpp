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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0 ;ListNode dummy(0); ListNode* curr = &dummy;

        while (l1 || l2 || carry){
            int v1 = l1 ? l1->val : 0; // condition ? valueiftrue : value if false
            int v2 = l2 ? l2->val : 0;
            int val = v1 + v2 + carry;

            carry = val / 10; // ex : 15 / 10 = 1
            val = val % 10;  // mod 10 get the one's digit ex: 15(mod 10) = 5

            curr->next = new ListNode(val);
            curr= curr->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        return dummy.next;
        
    }
};
