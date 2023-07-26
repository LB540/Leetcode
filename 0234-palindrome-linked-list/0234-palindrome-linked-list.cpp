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
    bool isPalindrome(ListNode* head) {
        ListNode* mid = getMid(head);
        ListNode* nh = reverse(mid);
        ListNode* hh = nh;
        while(head!=NULL && nh!=NULL) {
            if(head->val != nh->val) {
                break;
            }
            head=head->next;
            nh = nh->next;
        }
        reverse(hh);
        return head==NULL || nh==NULL;
    }
    
    ListNode* reverse(ListNode* node) {
        if(node==NULL) return node;
        
        ListNode* prev = NULL;
        ListNode* curr = node;
        while(curr!=NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow->next = NULL;
        return slow;
    }
};