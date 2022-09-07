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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head -> val == val)
            head = head -> next;
        if(head == NULL)
            return NULL;
        ListNode * itr = head -> next, *prev = head;
        while(itr){
            if(itr -> val == val)
                prev -> next = itr -> next;
            else
                prev = prev -> next;
            itr = itr -> next;
        }
        return head;
    }
};