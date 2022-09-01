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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next )
            return head;
        ListNode *prev = head, *nxt = head -> next;
        while(nxt){
            if(prev -> val != nxt -> val){
                prev -> next = nxt;
                prev = nxt;
            }
            nxt = nxt -> next;
        }
        prev -> next = NULL;
        return head;
    }
};