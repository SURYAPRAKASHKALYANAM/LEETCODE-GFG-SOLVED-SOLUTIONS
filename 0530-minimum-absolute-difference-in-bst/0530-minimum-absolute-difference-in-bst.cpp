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
        void findmin(vector<int> &v, TreeNode *root)
        {
            if (!root) return;
            findmin(v, root->left);
            v.emplace_back(root->val);
            findmin(v, root->right);
        }
    int getMinimumDifference(TreeNode *root)
    {
        int mini = INT_MAX;
        vector<int> v;
        findmin(v, root);
        for (auto i = 1; i < v.size(); i++) mini = min(mini, v[i] - v[i - 1]);
        return mini;
    }
};