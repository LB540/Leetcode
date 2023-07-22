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
    bool isPalindrome(ListNode* p1) {
        ListNode* mid = getMid(p1);
        ListNode* newH = reverse(mid);
        
        // ListNode* p1 = head;
        ListNode* p2 = newH;
        while(p1!=NULL && p2!=NULL) {
            if((p1->val)!=(p2->val)) break;
            p1=p1->next;
            p2=p2->next;
        }
        reverse(newH);
        return p1==NULL || p2==NULL;
    }
    
    ListNode* reverse(ListNode* head) {
        if(head==NULL) return head;
        
        ListNode* curr=head,*prev=NULL;
        while(curr!=NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev=curr;
            curr = temp;
        }
        return prev;
    }
    
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        while(head!=NULL && head->next!=NULL) {
            slow = slow->next;
            head = head->next->next;
        }
        return slow;
    }
};