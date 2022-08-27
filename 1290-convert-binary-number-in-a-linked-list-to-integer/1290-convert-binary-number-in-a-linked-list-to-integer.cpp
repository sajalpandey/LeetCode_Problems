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
    int getDecimalValue(ListNode* head) {
        int count=0; ListNode *ptr = head;
        while(ptr){
            count++;
            ptr = ptr->next;
        }
        int number = pow(2, count-1);
        ptr = head;count = 0;
        while(ptr)
        {
            count += ptr->val * number;
            number /= 2;
            ptr = ptr->next;
        }
        return count;
    }
};