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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = 1;
        TreeNode* ans = root;
        queue<TreeNode*> q, prev;
        q.push(root);
        prev.push(ans);
        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode*> order(n);
            for (int i = 0; i < n; i++) {
                auto it = q.front();q.pop();
                int ind = (level & 1) ? i : n - i - 1;
                order[ind] = it;
                if (it->left)
                    q.push(it->left);
                if (it->right)
                    q.push(it->right);
            }
            level++;
            int curr = 0;
            while (n > 1 && curr < n) {
                TreeNode* it = prev.front();prev.pop();
                it->left = order[curr];
                prev.push(order[curr++]);
                it->right = order[curr];
                prev.push(order[curr++]);
            }
        }
        return ans;
    }
};