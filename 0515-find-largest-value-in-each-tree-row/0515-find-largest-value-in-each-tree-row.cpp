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
        vector<int> largestValues(TreeNode *root)
        {
            if (!root) return {};
            vector<int> ans;
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                int n = q.size(), mmax = INT_MIN;
                for (int i = 0; i < n; i++)
                {
                    auto it = q.front();
                    q.pop();
                    mmax = max(it->val, mmax);
                    if (it->left) q.push(it->left);
                    if (it->right) q.push(it->right);
                }
                ans.emplace_back(mmax);
            }
            return ans;
        }
};