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
    void reverse(ListNode *s, ListNode *e){
        ListNode *p=NULL, *c=s,*n=s->next;
        while(p!=e){
            c->next=p;
            p=c;
            c=n;
            if(n!=NULL)
                n=n->next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k==1) return head;
        ListNode *dummyNode = new ListNode(0);
        dummyNode -> next = head;
        ListNode *prev = dummyNode, *end = head;
        int i = 0;
        while(end){
            i++;
            //this means we need to reverse the linked list
            if(i%k == 0){
                ListNode *start = prev->next;
                ListNode *nextPointer = end -> next;
                reverse(start, end);
                prev -> next = end;
                start -> next = nextPointer;
                prev = start;
                end = nextPointer;
            }
            else{
                end = end -> next;
            }
        }
        return dummyNode->next;
    }
};

/*Aproach

1. Create one dummy node and point it to head and 1 prev node which will point to dummyNode
2. Create a end node and iterate the linked list
3. when the counter value is equal to k means we need to reverse the ll from prev->next(start node) to end node , before calling reversal end->next needs to be stored.
4. After reversal pointer needs to be connected. Now connect prev->next to end and start->next to temp.
5. Now for next iteration our prev eill be start and end will be temp.


*/