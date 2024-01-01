/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
            string s = "";
            queue<TreeNode*> q;
            q.push(root);
            while (!q.empty())
            {
                auto it = q.front();
                q.pop();
                if (it == NULL) s += "#,";
                else s += to_string(it->val) + ',';
                if (it)
                {
                    q.push(it->left);
                    q.push(it->right);
                }
            }
            return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        queue<TreeNode*> q;
        TreeNode *root = new TreeNode(stoi(str));
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                auto it = q.front();
                q.pop();
                getline(s, str, ',');
                if (str == "#")
                {
                    it->left = NULL;
                }
                else
                {
                    it->left = new TreeNode(stoi(str));
                    q.push(it->left);
                }
                getline(s, str, ',');
                if (str == "#")
                {
                    it->right = NULL;
                }
                else
                {
                    it->right = new TreeNode(stoi(str));
                    q.push(it->right);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;