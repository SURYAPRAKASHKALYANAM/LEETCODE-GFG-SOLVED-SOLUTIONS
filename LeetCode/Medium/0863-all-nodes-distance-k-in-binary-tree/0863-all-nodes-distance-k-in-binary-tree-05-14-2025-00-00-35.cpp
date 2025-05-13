/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Solution
{
    public:
        void pre(TreeNode *root, map<TreeNode*, TreeNode*> &parent)
        {
            if (!root) return;
            if (root->left) parent[root->left] = root;
            if (root->right) parent[root->right] = root;
            pre(root->left, parent);
            pre(root->right, parent);
        }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        map<TreeNode*, TreeNode*> parent;
        pre(root, parent);
        int dis = 0;
        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        while (dis < k)
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
        vector<int> ans;
        while (!q.empty())
        {
            ans.emplace_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};