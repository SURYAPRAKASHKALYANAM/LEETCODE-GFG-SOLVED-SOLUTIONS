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
    int cnt = 0;
    void helper(TreeNode* root, vector<int> counts, int odd_cnt) {
        if (!root) {
            return;
        }
        if (counts[root->val]) {
            counts[root->val]--;
            odd_cnt--;
        } else {
            counts[root->val]++;
            odd_cnt++;
        }
        if (!root->left && !root->right) {
            cnt += (odd_cnt <= 1);
        } else {
            helper(root->left, counts, odd_cnt);
            helper(root->right, counts, odd_cnt);
        }
    }
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> counts(10, 0);
        int odd_cnt = 0;
        helper(root, counts, odd_cnt);
        return cnt;
    }
};