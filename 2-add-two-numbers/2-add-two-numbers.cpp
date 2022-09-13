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
        ListNode * dummy = new ListNode(-1);
        ListNode * curr = dummy;
        int carry = 0, sum;
        while(l1 && l2){
            sum = l1 -> val + l2 -> val + carry;
            if(sum > 9){
                sum = sum % 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            ListNode * newNode = new ListNode(sum);
            curr -> next = newNode;
            curr = curr -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1){
            sum = l1 -> val + carry;
            if(sum > 9){
                sum = sum % 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            ListNode * newNode = new ListNode(sum);
            curr -> next = newNode;
            curr = curr -> next;
            l1 = l1 -> next;
        }
        while(l2){
            sum = l2 -> val + carry;
            if(sum > 9){
                sum = sum % 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            ListNode * newNode = new ListNode(sum);
            curr -> next = newNode;
            curr = curr -> next;
            l2 = l2 -> next;
        }
        if(carry){
            ListNode * newNode = new ListNode(carry);
            curr -> next = newNode;
        }
        return dummy->next;
    }
};