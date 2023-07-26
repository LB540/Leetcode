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
    int getDecimalValue(ListNode* head) {
        string binary;
        while(head!=NULL) {
            // binary+= to_string(head->val);
            char c = (head->val?'1':'0');
            binary+=c;
            head = head->next;
        }
        reverse(binary.begin(),binary.end());
        // int n =stoi(binary);
        int res=0;
        int n =binary.length();
        
        for(int i=0;i<n;i++) {
            if(binary[i] == '1') {
                res+=pow(2,i);
            }
        }
        // for(int i=n-1;i>=0;i--) {
        //     if(binary[i]=='1') {
        //         res+= pow(2,n-i+1);
        //     }
        // }
        return res;
    }
};