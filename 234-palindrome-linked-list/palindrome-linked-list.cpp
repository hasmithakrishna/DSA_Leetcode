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
    ListNode* q;
    bool isPalindrome(ListNode* head) {
        ListNode* p = head;
        if(!q) q=p;
        if(!p) return true;
        bool result = isPalindrome(p->next);
        if(!result) return false;
        if(p->val != q->val) return false;
        q = q->next;
        return true;
        
    }
};