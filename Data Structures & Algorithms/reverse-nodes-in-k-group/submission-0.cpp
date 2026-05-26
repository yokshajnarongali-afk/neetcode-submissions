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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL)
        return NULL;

    // Step 1: check if at least k nodes exist
    ListNode* temp = head;
    int count = 0;

    while (count < k)
    {
        if (temp == NULL)
            return head;   // not enough nodes → no change
        temp = temp->next;
        count++;
    }

    // Step 2: recursively process remaining list
    ListNode* prevNode = reverseKGroup(temp, k);

    // Step 3: reverse current k nodes
    temp = head;
    count = 0;

    while (count < k)
    {
        ListNode* nextNode = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = nextNode;
        count++;
    }

    return prevNode;
    }
};
