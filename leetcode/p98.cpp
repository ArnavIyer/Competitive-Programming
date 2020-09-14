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
    bool ans;
    long long llmin(long long a, long long b) {
        if (a < b) return a;
        else return b;
    }
    long long llmax(long long a, long long b) {
        if (a > b) return a;
        else return b;
    }
    void traverse(TreeNode* curr, long long lmin, long long rmax) {
        if (curr->left != NULL) {
            if (curr->left->val <= lmin || curr->left->val >= curr->val) ans = false;
            traverse(curr->left,lmin,llmin(rmax, curr->val));
        }
        if (curr->right != NULL) {
            if (curr->right->val <= curr->val || curr->right->val >= rmax) ans = false;
            traverse(curr->right,llmax(lmin, curr->val), rmax);
        }
    }
    bool isValidBST(TreeNode* root) {
        ans=true;
        if (root == NULL) return true;
        traverse(root, LLONG_MIN,LLONG_MAX);
        return ans;
    }
};