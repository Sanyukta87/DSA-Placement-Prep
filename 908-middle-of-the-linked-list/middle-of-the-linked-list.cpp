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
        ListNode* middleNode(ListNode* head)
{
    ListNode* slow = head;       // Slow starts at head
    ListNode* fast = head;       // Fast starts at head

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       // Move 1 step
        fast = fast->next->next; // Move 2 steps
    }

    return slow;                 // Slow is at middle
    }
};