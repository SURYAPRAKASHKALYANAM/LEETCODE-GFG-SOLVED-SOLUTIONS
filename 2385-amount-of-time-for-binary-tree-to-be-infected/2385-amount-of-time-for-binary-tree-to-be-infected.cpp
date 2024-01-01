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
        TreeNode* find(int t, TreeNode *root)
        {
            if (!root) return NULL;
            if (root->val == t) return root;
            TreeNode *left = find(t, root->left);
            if (left) return left;
            TreeNode *right = find(t, root->right);
            if (right) return right;
            return NULL;
        }
    void pre(TreeNode *root, map<TreeNode*, TreeNode*> &parent)
    {
        if (!root) return;
        if (root->left) parent[root->left] = root;
        if (root->right) parent[root->right] = root;
        pre(root->left, parent);
        pre(root->right, parent);
    }
    int amountOfTime(TreeNode *root, int start)
    {
        TreeNode *target = find(start, root);
        map<TreeNode*, TreeNode*> parent;
        pre(root, parent);
        int dis = 0;
        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        while (!q.empty())
        {
            dis++;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                auto it = q.front();
                q.pop();
               	// move top
                if (parent[it] && !visited[parent[it]])
                {
                    q.push(parent[it]);
                    visited[parent[it]] = true;
                }
               	// move down-left,right
                if (it->left && !visited[it->left])
                {
                    q.push(it->left);
                    visited[it->left] = true;
                }
                if (it->right && !visited[it->right])
                {
                    q.push(it->right);
                    visited[it->right] = true;
                }
            }
        }
        return dis-1;
    }
};