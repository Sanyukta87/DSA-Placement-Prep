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
        ListNode* reverseList(ListNode* head)
{
    ListNode* prev = NULL;       // Previous node
    ListNode* curr = head;       // Current node
     ListNode*next;
     
    while(curr != NULL)
    {
        next = curr->next;       // Save next
        curr->next = prev;       // Reverse link
        prev = curr;             // Move prev
        curr = next;             // Move curr
    }

    return prev;                 // New head
    }
};