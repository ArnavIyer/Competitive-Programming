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
    int depth = INT_MAX;
    void d(TreeNode* root, int t) {
        if (root->left == NULL && root->right == NULL) {
            if (depth > t) depth = t;
            return;
        }
        if (root->left != NULL) d(root->left, t+1);
        if (root->right != NULL) d(root->right,t+1);
    }
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        d(root, 1);
        return depth;
    }
};