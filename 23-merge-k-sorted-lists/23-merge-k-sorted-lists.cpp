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
    ListNode * merge(ListNode *head1, ListNode *head2){
        ListNode *newHead = new ListNode(-1);
        ListNode *ptr = NULL;
        ptr = newHead;
        while(head1 && head2){
            if(head1 -> val <= head2 -> val){
                ptr -> next = head1;
                head1 = head1 -> next;
            }else{
                ptr -> next = head2;
                head2 = head2 -> next;
            }
            ptr = ptr -> next;
        }
        
        if(head2)
                ptr -> next = head2;
        if(head1)
                ptr -> next = head1;
        
        return newHead -> next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *mergedList = NULL;
        for(int i = 0; i < lists.size(); i++){
            mergedList = merge(mergedList, lists[i]);
        }
        return mergedList;
    }
};