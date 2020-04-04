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
        ListNode *current, *head;
        int result;
        result = l1 -> val + l2 -> val;
        head = current = new ListNode(result % 10);
        
        int carry = result / 10;
        
        while (l1 -> next != NULL && l2 -> next != NULL) {
            l1 = l1 -> next;
            l2 = l2 -> next;
            
            result = l1 -> val + l2 -> val + carry;
            current -> next = new ListNode(result % 10);
            current = current -> next;
            carry = result / 10;
        }
        
        while(l1 -> next != NULL) {
            l1 = l1 -> next;
            result = l1 -> val + carry;
            current -> next = new ListNode(result % 10);
            carry = result / 10;
            current = current -> next;
        }
        
        while(l2 -> next != NULL) {
            l2 = l2 -> next;
            result = l2 -> val + carry;
            current -> next = new ListNode(result % 10);
            carry = result / 10;
            current = current -> next;
        }
        
        if (carry > 0) {
            current -> next = new ListNode(carry);
        }
        
        return head;
    }
};
