/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};[1,2,null,3,null,4,null,5]
6[1,2]
1[]
0
 */
class Solution
{
    public:
    void root_to_path(TreeNode *root,int target, vector<vector < int>> &ans, vector< int > temp)
    {
       if(!root) return;
       if(root->left==NULL && root->right==NULL)
       {
           if(root->val==target)
           {
               temp.emplace_back(root->val);
               ans.emplace_back(temp);
               temp.pop_back();
           }
       }
       else if(root->left==NULL)
       {
           temp.emplace_back(root->val);
           root_to_path(root->right,target-(root->val),ans,temp);
           temp.pop_back();
       }
        else if(root->right==NULL)
        {
            temp.emplace_back(root->val);
           root_to_path(root->left,target-(root->val),ans,temp);
           temp.pop_back();
        }
        else 
        {
           temp.emplace_back(root->val);
            root_to_path(root->left,target-(root->val),ans,temp);
            root_to_path(root->right,target-(root->val),ans,temp);
           temp.pop_back(); 
        }
        return;
    }
    vector<vector <int>> pathSum(TreeNode *root, int targetSum) {
        vector<vector <int>> ans;
        root_to_path(root,targetSum,ans,{});
        return ans;
    }
};