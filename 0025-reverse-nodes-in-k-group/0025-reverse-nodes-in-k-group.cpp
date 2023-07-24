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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1 || head==NULL || head->next==NULL) return head;
        
        ListNode* curr=head,*prev=NULL;
        while(curr!=NULL) {
            ListNode* n = prev;
            ListNode* nn = curr;
            ListNode* safe=curr;
            for(int i=0;i<k;i++) {
                if(safe==NULL) return head;
                safe=safe->next;
            }
            for(int i=0;curr!=NULL && i<k;i++) {
                ListNode* temp =curr->next;
                curr->next = prev;
                prev=curr;
                curr=temp;
            }
            nn->next = curr; // after
            if(n!=NULL) {
                n->next = prev;  // before
            }else {
                head = prev;
            }
            prev = nn;
        }
        return head;
    }
    
};