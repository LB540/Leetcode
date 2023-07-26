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
        // ListNode* newNode= n->next;
        // ListNode* prev = n;
        // ListNode* curr = n->next;
        // while(curr!=NULL) {
        //     ListNode* temp = curr->next;
        //     curr->next = prev;
        //     prev= curr;
        //     curr = temp;
        // }
        // n->next = NULL;
        // newNode->next = head;
        // head = prev;
        // return head;
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next == NULL) return head;
        
        
        int size = 1;
        
        ListNode* temp = head;
        while(temp->next!=NULL){ temp=temp->next;size++;}
        k = k%size;
        size = size-k-1;
        ListNode* ptr = head;
        while(size--) {
            ptr = ptr->next; // 3
        }
        
        temp->next = head;
        head = ptr->next;
        ptr->next =NULL;
        
        return head;
        
    }
};