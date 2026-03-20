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
    ListNode* reverseList(ListNode* head) {
        ListNode *p=head;
        if(!p || !p->next) return p;
        ListNode* q = p->next;
        ListNode* newhead = reverseList(p->next);
        q->next = p;
        p->next = NULL;
        return newhead;

    }
};