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
    int lenCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        int len = 0;
        while(fast!=NULL && fast->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
            while(slow == fast) {
                ListNode* temp = slow;
                do {
                    temp = temp->next;
                    len++;
                }while(temp!=slow);
                return len;
            }
        }
        return len;
    }
    
    ListNode *detectCycle(ListNode *head) {
        int len = lenCycle(head);
        if(len==0) return NULL;
        ListNode* f = head;
        ListNode* s = head;
        
        while(len) {
            s = s->next;
            len--;
        }
        while(s!=f) {
            f=f->next;
            s=s->next;
        }
        return s;
    }
};