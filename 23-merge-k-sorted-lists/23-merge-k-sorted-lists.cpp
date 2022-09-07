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
    struct cmp{
        bool operator()(ListNode *a, ListNode *b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //make a min heap
        priority_queue<ListNode*, vector<ListNode*>,cmp> minH;
        //create a dummy node
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        for(auto &m: lists)
            if(m!=NULL)
                minH.push(m);
        while(minH.size()>0){
            ListNode *minNode = minH.top();
            minH.pop();
            tail -> next = minNode;
            tail = tail -> next;
            if(minNode!=NULL && minNode -> next != NULL)
                minH.push(minNode -> next);
        }
        return dummy -> next;
    }
};