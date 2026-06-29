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
    // vector<int> depthSum;
    // void dfs1(TreeNode* root, int d) {
    //     if (!root) return;
    //     if (d >= depthSum.size()) depthSum.push_back(root->val);
    //     else depthSum[d] += root->val;
    //     dfs1(root->left, d + 1);
    //     dfs1(root->right, d + 1);
    // }

    // void dfs2(TreeNode* root, int val, int d) {
    //     if (!root) return;
    //     root->val = val;
    //     int c = d + 1 < depthSum.size() ? depthSum[d + 1] : 0;
    //     c -= (root->left != nullptr ? root->left->val : 0);
    //     c -= (root->right != nullptr ? root->right->val : 0);
    //     if (root->left) dfs2(root->left, c, d + 1);
    //     if (root->right) dfs2(root->right, c, d + 1);
    // }
    // TreeNode* replaceValueInTree(TreeNode* root) {
        // dfs1(root, 0);
        // dfs2(root, 0, 0);
        // return root;
    // }
};