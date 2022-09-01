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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *mergeList = new ListNode(-1);
        ListNode *temp = mergeList;
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        
        while(list1 && list2){
            if(list1 -> val <= list2 -> val){
                ListNode *newNode = new ListNode(list1->val);
                temp ->next = newNode;
                list1 = list1 -> next;
                temp = temp -> next;
            }
            else {
                ListNode *newNode = new ListNode(list2->val);
                temp -> next = newNode;
                list2 = list2 -> next;
                temp = temp -> next;
            }
            //temp = temp -> next;
        }
        
        if(list1){
            temp ->next = list1;
        }
        else
            temp -> next = list2;
        
        return mergeList->next;
    }
    
};