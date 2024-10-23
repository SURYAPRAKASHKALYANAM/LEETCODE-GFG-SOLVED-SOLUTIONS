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
        TreeNode* replaceValueInTree(TreeNode *root)
        {
            queue<TreeNode*> q;
            root->val = 0;
            vector<int> levelsum;
            q.push(root);
            while (!q.empty())
            {
                int n = q.size();
                int sum = 0;
                for (int i = 0; i < n; i++)
                {
                    auto it = q.front();
                    q.pop();
                    sum += it->val;
                    if (it->left) q.push(it->left);
                    if (it->right) q.push(it->right);
                }
                levelsum.emplace_back(sum);
            }
            int level = 1, templ = 0;
            q.push(root);
            root->val = 0;
            while (!q.empty())
            {
                int n = q.size();
                for (int i = 0; i < n; i++)
                {
                    auto it = q.front();
                    q.pop();
                    if (it->left)
                    {
                        q.push(it->left);
                        templ = it->left->val;
                        it->left->val = (levelsum[level] - templ - ((it->right) ? it->right->val : 0));
                    }
                    if (it->right)
                    {
                        q.push(it->right);
                        it->right->val = (levelsum[level] - (it->right->val) - templ);
                    }
                    templ = 0;
                }
                level++;
            }
            return root;
        }
};