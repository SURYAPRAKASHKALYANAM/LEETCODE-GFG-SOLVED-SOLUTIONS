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
    void find(TreeNode *root,vector<int>& s,vector<vector<int>>& ans)
    {
        if(root==NULL) 
        {
            ans.emplace_back(s);
            return;
        }
        if(!(root->left) && !(root->right))
        {
            s.emplace_back(root->val);
            ans.emplace_back(s);
            s.pop_back();
            return;
        }
        else if(!(root->left))
        {
            s.emplace_back(root->val);
            find(root->right,s,ans);
            s.pop_back();
        }
        else if(!(root->right))
        {
             s.emplace_back(root->val);
             find(root->left,s,ans);
             s.pop_back();
        }
        else
        {
            s.emplace_back(root->val);
            find(root->left,s,ans);
            find(root->right,s,ans);
            s.pop_back();
        }  
    }
    int sumNumbers(TreeNode* root) 
    {
        vector<vector<int>> ans;
        vector<int> sub;
        find(root,sub,ans);
        int anss=0,s=0;
        for(auto i:ans)
        {
            for(int j=0;j<i.size();j++) 
            {
                s+=(i[j]*pow(10,i.size()-j-1));
            }
            anss+=s;
            s=0;
        }
        return anss;
        
    }
};