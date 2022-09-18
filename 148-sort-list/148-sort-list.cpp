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
    ListNode *merge(ListNode *left, ListNode *right){
        if(!left)
            return right;
        if(!right)
            return left;
        ListNode *dummy = new ListNode(-999);
        ListNode *ptr = dummy;
        while(left && right){
            if(left -> val < right -> val){
                ptr -> next = left;
                ptr = ptr -> next;
                left = left -> next;
            }
            else{
                ptr -> next = right;
                ptr = ptr -> next;
                right = right -> next;
            }
        }
        while(left){
            ptr -> next = left;
            ptr = ptr -> next;
            left = left -> next;
        }
        while(right){
            ptr -> next = right;
            ptr = ptr -> next;
            right = right -> next;
        }
        return dummy -> next;
    }
    ListNode *findMid(ListNode *head){
        ListNode *slow = head , *fast = head -> next;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;
        //find Mid
        ListNode * mid = findMid(head);
        
        ListNode *left = head, *right = mid -> next;
        mid -> next = NULL;
        
        //sort left and right part
        left = sortList(left);
        right = sortList(right);
        
        //merge sorted part;
        ListNode *result = merge(left, right);
        return result;
    }
};