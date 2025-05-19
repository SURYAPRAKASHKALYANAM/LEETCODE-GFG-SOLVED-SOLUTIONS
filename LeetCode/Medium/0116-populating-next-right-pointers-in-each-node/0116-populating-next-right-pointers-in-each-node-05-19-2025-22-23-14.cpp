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
        if (!root)
            return NULL;
        Node* temp = root;
        while (temp->left) {
            Node* row = temp;
            while (row) {
                Node* curr = row->left;
                curr->next = row->right;
                if (curr->next && row->next)
                    curr->next->next = row->next->left;
                row = row->next;
            }
            temp = temp->left;
        }
        return root;
    }
};