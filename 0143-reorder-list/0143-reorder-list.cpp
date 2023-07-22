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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;
        ListNode* mid = getMid(head);
        ListNode* nHead = reverse(mid);
        
        ListNode* temp;
        while(head!=NULL && nHead!=NULL){
            temp=head->next;
            head->next = nHead;
            head=temp;
    
            temp=nHead->next;
            nHead->next = head;
            nHead = temp;
        }
        if(head!=NULL) head->next=NULL;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while(head!=NULL) {
            ListNode* temp = head->next;
            head->next = prev;
            prev=head;
            head = temp;
        }
        return prev;
    }
    
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        while(head!=NULL && head->next!=NULL) {
            slow=slow->next;
            head=head->next->next;
        }
        return slow;
    }
};