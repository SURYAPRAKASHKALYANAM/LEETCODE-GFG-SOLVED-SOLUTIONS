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
        void findpath(string s, TreeNode *root, vector<string> &ans)
        {
            if (!root) return;
            if (root->left == NULL && root->right == NULL)
            {
                ans.emplace_back(s);
                return;
            }
            if (root->left)
            {
                s += "->";
                s += (to_string(root->left->val));
                int flag = 2;
                if (root->left->val < 0 && root->left->val > -10) flag += 2;
                else if (root->left->val == -100) flag += 4;
                else if (root->left->val > -100 && root->left->val <= -10) flag += 3;
                else if (root->left->val < 10) flag += 1;
                else if (root->left->val < 100) flag += 2;
                else flag += 3;
                findpath(s, root->left, ans);
                while (flag--) s.pop_back();
            }
            if (root->right)
            {
                s += "->";
                s += (to_string(root->right->val));
                int flag = 2;
                if (root->right->val < 0 && root->right->val > -10) flag += 2;
                else if (root->right->val == -100) flag += 4;
                else if (root->right->val > -100 && root->right->val <= -10) flag += 3;
                else if (root->right->val < 10) flag += 1;
                else if (root->right->val < 100) flag += 2;
                else flag += 3;
                findpath(s, root->right, ans);
                while (flag--) s.pop_back();
            }
        }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        string s = "";
        vector<string> ans;
        if (!root) return ans;
        s += to_string(root->val);
        findpath(s, root, ans);
        int c = 0;
        string ss = "23";
        return ans;
    }
};