/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int maxLevelSum(TreeNode *root)
        {
            int min_level = INT_MAX, max_sum = INT_MIN;
            queue<TreeNode*> q;
            q.push(root);
            int level = 1;
            if (root->val > max_sum)
            {
                max_sum = root->val;
                min_level = level;
            }
            while (!q.empty())
            {
                int n = q.size(), s = 0;
                for (int i = 0; i < n; i++)
                {
                    auto it = q.front();
                    q.pop();
                    s += it->val;
                    if (it->left) q.push(it->left);
                    if (it->right) q.push(it->right);
                }
                if (s > max_sum)
                {
                    max_sum = s;
                    min_level = level;
                }
                level++;
            }
            return min_level;
        }
};