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
        while(l1 || l2){
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum/10;
            sum = sum % 10;
            ListNode * newNode = new ListNode(sum);
            curr -> next = newNode;
            curr = curr -> next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        if(carry){
            ListNode * newNode = new ListNode(carry);
            curr -> next = newNode;
        }
        return dummy->next;
    }
};