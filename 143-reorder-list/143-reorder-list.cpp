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
    //Approach -1
    /*reorder(ListNode * head){
        ListNode *curr = head, *prev=NULL, *nxt = NULL;
        while(curr && curr -> next){
            ListNode *saveNextNode = curr -> next;
            nxt = curr;
            while(nxt -> next){
                prev = nxt ;
                nxt = nxt -> next;
            }
            prev -> next = NULL;
            curr -> next = nxt;
            if(saveNextNode != nxt)
                nxt -> next = saveNextNode;
            curr = curr -> next -> next;
    }*/
    ListNode * reverse(ListNode * head){
        ListNode *curr = head, *prev = NULL, *nxt;
        while(curr){
            nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head -> next;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *reversedHead = reverse(slow->next);
        slow -> next = NULL;
        slow = head;
        
        while(slow && reversedHead){
            ListNode *snext = slow -> next;
            ListNode * revNext = reversedHead -> next;
            slow -> next = reversedHead;
            reversedHead -> next = snext;
            slow = snext;
            reversedHead = revNext;
        }
    }
};