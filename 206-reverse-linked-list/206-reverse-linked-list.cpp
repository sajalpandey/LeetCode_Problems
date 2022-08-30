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
    ListNode* reverseList(ListNode* head) {
        ListNode *curr=head , *t1=NULL, *t2=NULL;
        while(curr){
            t1 = curr->next;
            curr->next= t2;
            t2 = curr;
            curr = t1;
        }
        return t2;
    }
};