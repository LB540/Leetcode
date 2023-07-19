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
    bool hasCycle(ListNode *head) {
        // ListNode* temp = head;
        // if(temp == NULL || temp->next == NULL) return false;
        // while(temp!=NULL && temp->val != NULL) {
        //     ListNode* node = temp;
        //     temp=temp->next;
        //     node->val = NULL;
        // }
        // if(temp == NULL) return false;
        // return true;
        ListNode* fast = head;
        ListNode* slow = slow;
        while(fast !=NULL && fast->next!= NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) return true;
        }
        return false;
    }
};