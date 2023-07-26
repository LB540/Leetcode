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
        string binary = "";
        while(head!=NULL) {
            binary+= to_string(head->val);
            head = head->next;
        }
        reverse(binary.begin(),binary.end());
        // int n =stoi(binary);
        int res=0;
        for(int i=0;i<binary.size();i++) {
            if(binary[i]=='1') {
                res+=pow(2,i);
            }
        }
        return res;
    }
};