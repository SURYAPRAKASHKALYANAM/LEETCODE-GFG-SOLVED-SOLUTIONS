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
        Node* dummyHead = new Node(-1);
        Node *dummy = dummyHead, *temp = head;
        while (temp) {
            Node* next = temp->next;
            temp->next = new Node(temp->val, next);
            temp = next;
        }
        temp = head;
        while (temp) {
            Node* newNode = temp->next;
            if (temp->random)
                newNode->random = temp->random->next;
            else
                newNode->random = nullptr;
            temp = newNode->next;
        }
        temp = head;
        while (temp) {
            Node* newNode = temp->next;
            dummy = dummy->next = newNode;
            temp = temp->next = newNode ? newNode->next : nullptr;
        }

        return dummyHead->next;
    }
};