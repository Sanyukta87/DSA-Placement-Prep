/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both empty → same
        if(p == NULL && q == NULL)
            return true;

        // One empty → different
        if(p == NULL || q == NULL)
            return false;

        // Values different → different
        if(p->val != q->val)
            return false;

        // Compare left and right subtrees
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        // Both sides must be same
        return left && right; 
    }
};