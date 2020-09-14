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
    void ans(TreeNode* root, vector<int> path, int pathsum, int& sum, vector<vector<int>>& nums) {
        path.push_back(root->val);
        pathsum += root->val;
        bool left = root->left == NULL;
        bool right = root->right == NULL;
        if (left && right) {
            if (pathsum == sum) nums.push_back(path);
            return;
        }
        if (!left) ans(root->left, path, pathsum, sum, nums);
        if (!right) ans(root->right, path, pathsum, sum, nums);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> nums;
        vector<int> path;
        if (root != NULL) ans(root, path, 0, sum, nums);
        return nums;
    }
};