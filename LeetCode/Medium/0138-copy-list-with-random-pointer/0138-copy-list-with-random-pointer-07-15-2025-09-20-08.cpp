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
        unordered_map<Node*, Node*> pointsTo, newNodeMap;
        Node *temp = head, *newList = NULL, *prev;
        while (temp) {
            pointsTo[temp] = temp->random;
            Node* newNode = new Node(temp->val);
            newNodeMap[temp] = newNode;
            if (!newList) {
                newList = newNode;
            } else {
                prev->next = newNode;
            }
            prev = newNode;
            temp = temp->next;
        }
        temp = head;
        while (temp) {
            newNodeMap[temp]->random =
                newNodeMap[temp->random] ? newNodeMap[temp->random] : NULL;
            temp = temp->next;
        }
        return newList;
    }
};