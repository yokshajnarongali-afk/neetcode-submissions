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

ListNode* reverseList (ListNode* head)
{
    if (head == NULL || head -> next == NULL)
    {
        return head ;
    }
    ListNode* c = head ;
    ListNode* p = nullptr ;
    while (c)
    {
        ListNode* n = c -> next ;
        c -> next = p ;
        p = c ;
        c = n ;
    }

    return p ;
}

    void reorderList(ListNode* head) {
         ListNode* s = head ;
    ListNode* f = head ;

    while (f != NULL && f -> next != NULL)
    {
        s = s -> next ;
        f = f -> next -> next ;
    }

    ListNode* head2 = reverseList (s -> next) ;
    s -> next = NULL ;
    ListNode* head1 = head ;

    while (head2 != NULL)
    {
        
        ListNode* t1 = head1 -> next ;
        ListNode* t2 = head2 -> next ;

        head1 -> next = head2 ;
        head2 -> next = t1 ;

        head1 = t1 ;
        head2 = t2 ;
    }
    }
};
