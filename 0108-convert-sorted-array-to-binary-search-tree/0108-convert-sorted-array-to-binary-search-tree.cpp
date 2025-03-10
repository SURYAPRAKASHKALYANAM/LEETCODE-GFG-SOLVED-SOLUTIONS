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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int mid = (r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {l, mid - 1}});
        q.push({root, {mid + 1, r}});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            l = it.second.first, r = it.second.second;
            if (l > r)
                continue;
            mid = (l + r) / 2;
            auto node = new TreeNode(nums[mid]);
            if (nums[mid] < it.first->val) {
                it.first->left = node;
            } else {
                it.first->right = node;
            }
            q.push({node, {l, mid - 1}});
            q.push({node, {mid + 1, r}});
        }
        return root;
    }
};