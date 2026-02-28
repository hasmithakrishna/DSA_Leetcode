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
        if(!headA || !headB) return NULL;
        ListNode *p = headA;
        stack<ListNode*> s1,s2;
        while(p){
            s1.push(p);
            p=p->next;
        }
        p = headB;
        while(p){
            s2.push(p);
            p=p->next;
        }
        ListNode *intersection=NULL;
        while(!s1.empty() && !s2.empty() && s1.top()==s2.top()){
            intersection = s1.top();
            s1.pop();
            s2.pop();
        }

        return intersection; 
    }
};