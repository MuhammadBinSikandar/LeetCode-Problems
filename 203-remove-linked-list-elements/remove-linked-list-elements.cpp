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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        ListNode *dummy= new ListNode(-1, head);
        ListNode* curr = dummy;
        while(curr!=NULL){
            if(curr->next!=NULL && curr->next->val == val){
                curr->next = curr->next->next;
            }else{
                curr=curr->next;
            }
            
        }
        return dummy->next;
    }
};