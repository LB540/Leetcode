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
    ListNode* mergeTwoLists(ListNode* ptr1, ListNode* ptr2) {
        // ListNode* ptr1 = list1;
        // ListNode* ptr2 = list2;
        ListNode* temp = new ListNode();
        ListNode* tail = temp;
        
        while(ptr1!=NULL & ptr2!=NULL) {
            if(ptr1->val <= ptr2->val) {
                tail->next = ptr1;
                ptr1 = ptr1->next;
                tail = tail->next;
            }else {
                tail->next = ptr2;
                ptr2 = ptr2->next;
                tail = tail->next;
            }
        }
        tail->next = (ptr1!=NULL)?ptr1:ptr2;
        return temp->next;
    }
};