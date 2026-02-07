/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void find(TreeNode* root, int& s, int& totSum) {
        if (!root)
            return;
        s = s * 10 + (root->val);
        if (!root->left && !root->right) {
            totSum += s;
        }
        find(root->left, s, totSum);
        find(root->right, s, totSum);
        s /= 10;
    }
    int sumNumbers(TreeNode* root) {
        int s = 0;
        int totSum = 0;
        find(root, s, totSum);
        return totSum;
    }
};