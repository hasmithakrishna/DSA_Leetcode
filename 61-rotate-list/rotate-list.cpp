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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p, *q;
        if(!head || !head->next|| k ==0) return head;
            int len = 0;
            p = head;
            while(p){
                len++;
                p=p->next;
                }
                k %= len;
                if(k == 0) return head;
                p = head;
                for(int i=1; i< len-k; i++){
                    p = p->next;
                }
                q=p->next;
                p->next = NULL;
                ListNode *temp = q;
                while(temp->next){
                    temp = temp->next;
                }
                temp->next = head;
                return q;
    }
};