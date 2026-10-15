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
    int getDecimalValue(ListNode* head) {
        vector<int> v;
        while(head!=NULL)
        {
            v.emplace_back(head->val);
            head=head->next;
        }
        int e=v.size();
        int s=0;
        for(int i=0;i<v.size();i++)
        {
            s+=pow(2,e-1)*v[i];
            e--;
        }
        return s;
    }
};