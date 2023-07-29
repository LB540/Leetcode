/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void copyList(Node* head) {
        Node* temp=head, *n=head->next;
        while(temp!=NULL) {
            Node* newNode = new Node(temp->val);
            temp->next = newNode;
            newNode->next = n;
            temp = n;
            if(n!=NULL)n = n->next;
        }
    }
    
    void randHandle(Node* head) {
        Node* temp = head;
        while(temp!=NULL) {
            if(temp->random!=NULL)
                temp->next->random = temp->random->next;
            else 
                temp->next->random = NULL;
            temp = temp->next->next;
        }
    }
    
    Node* resetList(Node* head) {
        Node* dummy = new Node(-1);
        Node* tail = dummy, *temp = head;
        while(temp!=NULL) {
            tail->next = temp->next;
            tail = tail->next;
            temp->next = tail->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        copyList(head);
        randHandle(head);
        return resetList(head);
    }
};