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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head; // checks if the head is NULL and returns directly
                         // without checking
        ListNode* curr = new ListNode(
            0, head); // creates a dummy node which is linked with the head node
        ListNode* prev =
            curr; // a node to store the previous node of the current node
        while (head != NULL) { // a loop that operates until the head is not
                               // NULL
            if (head->next != NULL &&
                head->val ==
                    head->next->val) { /* if head is not NULL and the value of
                                          head node is equal to the value of the
                                          next node */
                while (head->next != NULL &&
                       head->val ==
                           head->next
                               ->val) { /* loop that iterates until head's next
                                           is not NULL and the value of head
                                           node is equal the next node value*/
                    head = head->next;  /* moves the hed node to the next */
                }
                prev->next =
                    head->next; /*after the loop finishes we have skipped all
                                   the nodes which have the same value and we
                                   have the instance of the node prev which has
                                   the different value and we skip same values
                                   nodes and link the previous node with the
                                   next node of all the similar values*/
            } else {
                prev = prev->next; /* if the above coniditon is not saitsfies we
                                      move the previous node to the next means
                                      that curr node and next node have
                                      different value*/
            }
            head = head->next; // then we move the head to the next node
        }
        return curr->next; // return the next node of the dummy node we created
                           // at the start
    }
};