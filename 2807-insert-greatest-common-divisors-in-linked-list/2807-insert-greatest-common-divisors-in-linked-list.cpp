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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *prev=head,*next_node=head->next;
        while(prev && next_node)
        {
            auto i=new ListNode(__gcd(prev->val,next_node->val),next_node);
            prev->next=i;
            prev=next_node;
            next_node=next_node->next;
        }
        return head;
    }
};