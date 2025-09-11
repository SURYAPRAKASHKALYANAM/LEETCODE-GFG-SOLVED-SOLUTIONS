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
        Node* temp = head;
        while (temp) {
            temp->next = new Node(temp->val, temp->next, nullptr);
            temp = temp->next->next;
        }
        temp = head;
        while (temp) {
            Node* newNode = temp->next;
            newNode->random = temp->random ? temp->random->next : nullptr;
            temp = newNode->next;
        }
        temp = head;
        Node* dummy = new Node(-1);
        Node* dummyNode = dummy;
        while (temp) {
            Node* newNode = temp->next;
            dummy = dummy->next = newNode;
            temp = temp->next = newNode ? newNode->next : nullptr;
        }
        return dummyNode->next;
    }
};