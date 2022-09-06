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
    bool isPalindrome(ListNode* head) {
        string str = "";
        ListNode *itr = head;
        while(itr){
            str += to_string(itr->val);
            itr = itr -> next;
        }
        
        string reverseString = str;
        reverse(str.begin(), str.end());
        if(str == reverseString)
            return true;
        return false;
    }
};