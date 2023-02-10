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
    ListNode* removeNodes(ListNode* head) 
    {
        stack<pair<int,ListNode*>> s;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(s.empty())   s.push(make_pair(temp->val,temp));
            else
            {
                pair<int,ListNode*> t=s.top();
                while(!s.empty() && s.top().first < temp->val) s.pop();
                s.push(make_pair(temp->val,temp));   
            }
            temp=temp->next;
        }
        while(!s.empty())                               //POP -INSERT  BEGIN
        {
            if(!temp)
            {
                temp=s.top().second;
                temp->next=NULL;
                s.pop();
            }
            else
            {
                s.top().second->next=temp;
                temp=s.top().second;
                s.pop();
            }
        }
        return temp;
    }
};