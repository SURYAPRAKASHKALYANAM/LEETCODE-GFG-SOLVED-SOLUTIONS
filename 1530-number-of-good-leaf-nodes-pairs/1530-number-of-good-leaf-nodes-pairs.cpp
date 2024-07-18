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
    unordered_map<TreeNode*, TreeNode*> parent;
    vector<TreeNode*> leaf;
    void findParent(TreeNode *root)
    {
        if (!root) return;
        else if (!root->left && !root->right)
        {
            leaf.emplace_back(root);
            return;
        }
        if (root->left)
        {
            parent[root->left] = root;
            findParent(root->left);
        }
        if (root->right)
        {
            parent[root->right] = root;
            findParent(root->right);
        }
    }
    void Atdistance(TreeNode* root,int distance,int &pairs)
    {
        unordered_map<TreeNode*, bool> visited;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        visited[root]=1;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            if(it.first!=root && !(it.first->left) && !(it.first->right) && it.second<=distance) pairs++;
            if(it.second<distance)
            {
                // top
                if(parent[it.first]!=NULL && !visited[parent[it.first]])
                {
                    q.push({parent[it.first],it.second+1});
                    visited[parent[it.first]]=1;
                }
                //left
                if(it.first->left && !visited[it.first->left])
                {
                    q.push({it.first->left,it.second+1});
                    visited[it.first->left]=1;
                }
                
                //right
                if(it.first->right && !visited[it.first->right])
                {
                    q.push({it.first->right,it.second+1});
                    visited[it.first->right]=1;
                }
            }
        }
    }
    int countPairs(TreeNode *root, int distance)
    {
        findParent(root);
        int pairs=0;
        for(auto i:leaf)
        {
            Atdistance(i,distance,pairs);
        }
        return pairs/2;
    }
};