/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* add(ListNode* node1, ListNode* node2, int carry) {
        ListNode* node = nullptr;
        int sum = carry;
        if (node1 && node2) {
            sum += node1->val + node2->val;
            node = new ListNode(sum % 10);
            node->next = add(node1->next, node2->next, sum / 10);
        } else if (node1) {
            sum += node1->val;
            node = new ListNode(sum % 10);
            node->next = add(node1->next, nullptr, sum / 10);
        } else if (node2) {
            sum += node2->val;
            node = new ListNode(sum % 10);
            node->next = add(nullptr, node2->next, sum / 10);
        } else if (carry) {
            node = new ListNode(carry % 10);
            node->next = add(nullptr, nullptr, carry / 10);
        }
        return node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
};