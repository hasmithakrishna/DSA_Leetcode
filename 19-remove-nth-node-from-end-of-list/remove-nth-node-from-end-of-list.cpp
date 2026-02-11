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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode *l = head;
        ListNode *r = head;
        for(int i=0; i<n; i++){
            r = r->next;
        }
        if(!r){
            ListNode *dummy = head;
            head = head->next;
            delete dummy;
            return head;
        }
        while(r->next != NULL){
            r= r->next;
            l=l->next;
        }
        ListNode *dummy = l->next;
        l->next = dummy->next;
        delete dummy;
        return head;



    }
};