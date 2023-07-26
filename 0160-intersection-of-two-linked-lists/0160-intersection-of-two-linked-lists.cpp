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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int size1=0;
        int size2=0;
        while(temp1!=NULL){
            temp1 = temp1->next;
            size1++;
        }
        while(temp2!=NULL){
            temp2 = temp2->next;
            size2++;
        }
        int size_t;
        if(size1>size2) {
            size_t = size1-size2;
            while(size_t--) {
                headA=headA->next;
            }
        }else {
            size_t = size2-size1;
            while(size_t--) {
                headB=headB->next;
            }
        }
        while(headA!=NULL && headB!=NULL && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        if(headA ==NULL || headB == NULL) return NULL;
        return headA;
    }
};