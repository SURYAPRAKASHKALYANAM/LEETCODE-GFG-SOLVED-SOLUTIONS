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

class Node {
public:
    long long max_val, min_val;
    int sum = 0, max_sum = 0;

    Node(long long max_val, long long min_val, int sum, int max_sum)
        : max_val(max_val), min_val(min_val) {
        this->sum = sum;
        this->max_sum = max_sum;
    }
};

class Solution {
public:
    Node isValid(TreeNode* root) {
        if (!root)
            return Node(LLONG_MIN, LLONG_MAX, 0, 0);
        Node left = isValid(root->left);
        Node right = isValid(root->right);
        // subtree max
        int sub_max = max(left.max_sum, right.max_sum);
        if (root->val > left.max_val && root->val < right.min_val) {
            // valid bst
            return Node(max(root->val*1LL, right.max_val),
                        min(root->val*1LL, left.min_val),
                        root->val + left.sum + right.sum,
                        max(root->val + left.sum + right.sum, sub_max));
        }
        // not a bst
        return Node(LLONG_MAX, LLONG_MIN, 0, sub_max);
    }
    int maxSumBST(TreeNode* root) { return isValid(root).max_sum; }
};