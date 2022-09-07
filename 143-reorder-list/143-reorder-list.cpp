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
    void reorderList(ListNode* head) {
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
        }
    }
};