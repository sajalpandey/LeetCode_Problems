/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node *, Node *> mp;
        Node * curr = head;
        //added newly created duplicate nodes in between ll
        while(curr){
            Node *newNode = new Node(curr->val);
            newNode -> next = curr -> next;
            curr -> next = newNode;
            curr = newNode -> next;
        }
        //now correct random nodes
        curr = head;
        while(curr){
            curr -> next -> random = (curr->random ? curr -> random -> next : NULL);
            curr = curr -> next -> next;
        }
        //correct the linked list
        Node *dummy = new Node(-1);
        Node * itr = dummy;curr = head;
        while(curr){
            itr->next = curr->next;
            itr = itr -> next;
            curr -> next = itr -> next;
            curr = curr -> next;
        }
        return dummy -> next;
    }
};