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

    bool isMirror(TreeNode* p, TreeNode* q)
    {
        // Both empty → mirror
        if(p == NULL && q == NULL)
            return true;

        // One empty → not mirror
        if(p == NULL || q == NULL)
            return false;

        // Values must match
        if(p->val != q->val)
            return false;

        // Mirror: left ↔ right
        bool left = isMirror(p->left, q->right);
        bool right = isMirror(p->right, q->left);

        // Both sides must be mirror
        return left && right;
    }

    bool isSymmetric(TreeNode* root)
    {
        if(root == NULL)
            return true;

        return isMirror(root->left, root->right);
    }
};