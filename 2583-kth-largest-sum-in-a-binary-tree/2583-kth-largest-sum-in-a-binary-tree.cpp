/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        long long kthLargestLevelSum(TreeNode *root, int k)
        {
            queue<TreeNode*> q;
            vector < long long > ans;
            q.push(root);
            while (!q.empty())
            {
                int n = q.size();
                long long s = 0;
                for (int i = 0; i < n; i++)
                {
                    auto it = q.front();
                    q.pop();
                    s += it->val;
                    if (it->left) q.push(it->left);
                    if (it->right) q.push(it->right);
                }
                ans.emplace_back(s);
            }
            sort(ans.begin(), ans.end());
            return ((int) ans.size() - k) < 0 ? -1 : ans[(int) ans.size() - k];
        }
};