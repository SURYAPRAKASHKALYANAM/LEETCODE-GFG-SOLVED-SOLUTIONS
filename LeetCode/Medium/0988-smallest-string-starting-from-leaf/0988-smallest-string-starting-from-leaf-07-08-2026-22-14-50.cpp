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
        char charof(int n)
        {
            return "abcdefghijklmnopqrstuvwxyz"[n];
        }
    void dfs(TreeNode *root, string s, set<string> &strs)
    {
        if (!root) return;
        if (root->left == NULL && root->right == NULL)
        {
            s += charof(root->val);
            reverse(s.begin(), s.end());
            strs.insert(s);
            return;
        }
        s += charof(root->val);
        if (root->left) dfs(root->left, s, strs);
        if (root->right) dfs(root->right, s, strs);
    }
    string smallestFromLeaf(TreeNode *root)
    {
        set<string> s;
        dfs(root, "", s);
        return *s.begin();
    }
};