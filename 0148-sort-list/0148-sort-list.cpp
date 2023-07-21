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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left,right);
    }
    
    ListNode* merge(ListNode* l,ListNode* r) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while(l!=NULL && r!=NULL) {
            if(l->val<=r->val) {
                temp->next = l;
                l=l->next;
                temp = temp->next;
            }else {
                temp->next = r;
                r=r->next;
                temp = temp->next;
            }
        }
        if(l!=NULL) {
            temp->next = l;
        }else {
            temp->next =r;
        }
        return dummy->next;
    }
    
    ListNode* getMid(ListNode* head) {
        ListNode* ptr = NULL;
        while(head!=NULL && head->next!=NULL) {
            ptr = ptr == NULL?head:ptr->next;
            head = head->next->next;
        }
        ListNode* temp = ptr->next;
        ptr->next = NULL;
        return temp;
    }
};