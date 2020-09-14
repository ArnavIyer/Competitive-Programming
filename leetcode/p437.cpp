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
    int ct;
    void traverse(TreeNode* curr, vector<int> sums, int& num) {
        for (int i = 0; i<sums.size(); i++) {
            sums[i] += curr->val;
        }
        sums.push_back(curr->val);
        if (curr->left != NULL) traverse(curr->left, sums, num);
        if (curr->right != NULL) traverse(curr->right, sums, num);
        for (auto i : sums) {
            if (i == num) ct++;
        }
    }
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        ct=0;
        vector<int> a;
        traverse(root, a, sum);
        return ct;
    }
};