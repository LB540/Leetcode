//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head == NULL || head->next == NULL) return head;
        
        Node* mid = getMid(head);
        
        Node* f = mergeSort(head);
        Node* s = mergeSort(mid);
        
        return merge(f,s);
    }
    
    Node* merge(Node* a, Node* b) {
        // Node* f = a;
        // Node* s = b;
        Node* dummy = new Node(0);
        Node* tail = dummy;
        while(a!=NULL && b!=NULL) {
            if(a->data <= b->data) {
                tail->next = a;
                a = a->next;
                tail = tail->next;
            }else {
                tail->next = b;
                b = b->next;
                tail = tail->next;
            }
        }
        
        if(a!=NULL) {
            tail->next = a;
        }else {
            tail->next = b;
        }
        return dummy->next;
    }
    
    Node* getMid(Node* head) {
        Node* slow = NULL;
        while(head!=NULL && head->next!=NULL) {
            slow = (slow==NULL)?head:slow->next;
            head = head->next->next;
        }
        // slow->next = NULL
        Node* temp = slow->next;
        slow->next = NULL;
        return temp;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends