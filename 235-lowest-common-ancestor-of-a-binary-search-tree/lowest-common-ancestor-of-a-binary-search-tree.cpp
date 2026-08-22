/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
*     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,
                                    TreeNode* p,
                                    TreeNode* q)
    {
        if(root == NULL)
            return NULL;

        // Both smaller → go left
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);

        // Both greater → go right
        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        // They split here → current root is LCA
        return root;
    }
};