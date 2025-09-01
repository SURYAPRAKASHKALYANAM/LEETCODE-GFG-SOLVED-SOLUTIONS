/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(-1);
        Node *temp = head, *tempDummy = dummy;
        unordered_map<Node*, Node*> newNode;
        while (temp) {
            newNode[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp) {
            dummy->next = newNode[temp];
            newNode[temp]->next = newNode[temp->next];
            newNode[temp]->random = newNode[temp->random];
            dummy = dummy->next;
            temp = temp->next;
        }
        return tempDummy->next;
    }
};