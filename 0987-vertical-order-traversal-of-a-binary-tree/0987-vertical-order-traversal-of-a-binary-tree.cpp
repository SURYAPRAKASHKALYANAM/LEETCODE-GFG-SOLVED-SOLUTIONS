/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> todo;
        todo.push({root,make_pair(0,0)});
        while(!todo.empty())
        {
            auto it=todo.front();
            todo.pop();
            int x=it.second.first,y=it.second.second;
            nodes[x][y].insert(it.first->val);
            if(it.first->left) todo.push({it.first->left,{x-1,y+1}});
            if(it.first->right) todo.push({it.first->right,{x+1,y+1}});
        }
        for(auto p:nodes)
        {
            vector<int> col;
            for(auto lev:p.second)
            {
                col.insert(col.end(),lev.second.begin(),lev.second.end());
            }
            ans.emplace_back(col);
        }
        return ans;
        
    }
};