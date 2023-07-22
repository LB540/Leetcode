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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(right==left) return head;
        
        ListNode* curr=head,*prev = NULL;
        for(int i=0;curr!=NULL && i<left-1;i++) {
            prev = curr;
            curr = curr->next;
        }
        ListNode* last = prev;
        ListNode* newNode = curr;
        
        ListNode* n = curr->next;
        for(int i=0;curr!=NULL && i<right-left+1;i++) {
            curr->next = prev;
            prev= curr;
            curr = n;
            if(n!=NULL) {
                n=n->next;
            }
        }
        
        if(last!=NULL) {
            last->next = prev;   
        }else{
            head = prev;
        }
        newNode->next = curr;
        return head;
    }
};