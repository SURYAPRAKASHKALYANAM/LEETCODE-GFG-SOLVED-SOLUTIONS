/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        root->next=NULL;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto it=q.front();
                q.pop();
                if(!q.empty() && i!=n-1) it->next=q.front();
                if(i==n-1 && it) it->next=NULL;
                if(it && it->left ) q.push(it->left);
                if(it && it->right )  q.push(it->right);
            }
        }
        return root;
        
    }
};