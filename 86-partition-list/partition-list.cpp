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
// class Solution {
// public:
//     ListNode* partition(ListNode* head, int x) {
//         ListNode *lessHead = new ListNode(0);
//         ListNode *greaterHead = new ListNode(0);
//         ListNode *less = lessHead;
//         ListNode *greater = greaterHead;
//         while (head != nullptr) {
//             if (head->val < x) {
//                 less->next = head;
//                 less = less->next;
//             } else {
//                 greater->next = head;
//                 greater = greater->next;
//             }
//             head = head->next;
//         }
//         greater->next = nullptr;
//         less->next = greaterHead->next;
//         ListNode* partitionedHead = lessHead->next;
//         delete lessHead;
//         delete greaterHead;
//         return partitionedHead;
//     }
// };

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* smaller = new ListNode(-1);  // Dummy node for smaller list
        ListNode* larger = new ListNode(-1);  // Dummy node for larger list
        ListNode* smallerHead = smaller;      // Store the head of the smaller list
        ListNode* largerHead = larger;        // Store the head of the larger list

        while (head != nullptr) {
            if (head->val < x) {
                smaller->next = new ListNode(head->val);
                smaller = smaller->next;
            } else {
                larger->next = new ListNode(head->val);
                larger = larger->next;
            }
            head = head->next;
        }

        smaller->next = largerHead->next;  // Combine lists after skipping dummy nodes
        return smallerHead->next;          // Return the head of the combined list (skipping dummy node)
    }
};

