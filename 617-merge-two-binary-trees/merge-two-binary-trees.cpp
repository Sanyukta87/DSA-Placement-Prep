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
    TreeNode* mergeTrees(TreeNode* a, TreeNode* b)
    {
        if(a == NULL && b == NULL)
            return NULL;

        if(a == NULL)
            return b;

        if(b == NULL)
            return a;

        a->val = a->val + b->val;

        a->left = mergeTrees(a->left, b->left);
        a->right = mergeTrees(a->right, b->right);

        return a;
    }
};