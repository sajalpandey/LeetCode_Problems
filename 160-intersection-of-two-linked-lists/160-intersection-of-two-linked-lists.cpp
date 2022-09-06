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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count1 = 0, count2 = 0;
        ListNode *ptr1 = headA, *ptr2 = headB;
        while(ptr1){
            count1++;
            ptr1 = ptr1 -> next;
        }
        while(ptr2){
            count2++;
            ptr2 = ptr2 -> next;
        }
        ptr1 = headA, ptr2 = headB;
        while((count1 - count2) > 0){
            ptr1 = ptr1 -> next;
            count1--;
        }
        
        while((count2 - count1) > 0){
            ptr2 = ptr2 -> next;
            count2--;
        }
        
        while(ptr1 != ptr2){
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        return ptr1;
    }
};