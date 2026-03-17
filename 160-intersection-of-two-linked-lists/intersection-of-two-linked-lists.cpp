/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA;
        ListNode *q = headB;
        stack<ListNode*> st1;
        stack<ListNode*> st2;
        while(p){
            st1.push(p);
            p=p->next;
        }
        while(q){
            st2.push(q);
            q = q->next;
        }
        ListNode* intersection = NULL;
        while(!st1.empty() && !st2.empty() && st1.top()==st2.top()){
            intersection = st1.top();
            st1.pop();
            st2.pop();
        }
        return intersection;


        
    }
};