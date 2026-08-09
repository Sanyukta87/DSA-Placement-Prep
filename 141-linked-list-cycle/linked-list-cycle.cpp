/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        ListNode* slow = head;       // Slow moves 1 step
        ListNode* fast = head;       // Fast moves 2 steps

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;       // Move 1 step
            fast = fast->next->next; // Move 2 steps

            if(slow == fast)         // They meet → cycle exists
                return true;
        }

        return false;                // Fast reached NULL → no cycle
    }
};