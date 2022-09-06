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
    ListNode * reverse(ListNode *head){
        ListNode *curr = head, *prev = NULL, *nxt = NULL;
        while(curr){
            nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head , *fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        ListNode *reversedHead = NULL;
        if(fast == NULL)
            reversedHead = reverse(slow);
        else
            reversedHead = reverse(slow -> next);
        
        fast = head;
        while(fast && reversedHead){
            if(fast->val != reversedHead->val)
                return false;
            fast = fast -> next;
            reversedHead = reversedHead -> next;
        }
        
        return true;
    }
};