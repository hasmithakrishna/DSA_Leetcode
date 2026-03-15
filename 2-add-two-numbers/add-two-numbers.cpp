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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* i = l1;
        ListNode* j = l2;
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* k = dummy;
        while(i || j){
            int sum = carry;
            if(i) sum += i->val;
            if(j) sum += j->val;
            k->next = new ListNode(sum%10);
            carry = sum/10;
            k = k->next;
            if(i) i=i->next;
            if(j) j = j->next;

        }
        if(carry){
            k->next = new ListNode(carry);
        }
        return dummy->next;
    }
};