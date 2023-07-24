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
    
    void reverse(ListNode* s,ListNode* e) {
        ListNode* prev=NULL,*curr=s,*temp;
        while(prev!=e) {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1 || head==NULL || head->next==NULL) return head;
        ListNode* s=head,*e=head;
        int inc=k-1;
        while(inc--) {
            e=e->next;
            if(e==NULL) return head;
        }
        ListNode* newNode = reverseKGroup(e->next,k);
        reverse(s,e);
        s->next = newNode;
        return e;
    }
};