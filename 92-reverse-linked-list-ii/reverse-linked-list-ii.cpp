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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || head->next == NULL) {
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        // Pointers for traversing the list
        ListNode* current = dummy;
        ListNode* previous = NULL;

        // Find the node before the leftmost node to be reversed
        for (int i = 0; i < left; i++) {
            previous = current;
            current = current->next;
        }

        // Pointers for reversing the sublist
        ListNode* reversedTail = previous;
        ListNode* reversedHead = current;

        // Reverse the linked list between left and right
        for (int i = left; i <= right; i++) {
            ListNode* nextNode = reversedHead->next;
            reversedHead->next = reversedTail;
            reversedTail = reversedHead;
            reversedHead = nextNode;
        }

        // Connect the reversed sublist with the rest of the list
        previous->next = reversedTail;
        current->next = reversedHead;

        return dummy->next;
    }
};



