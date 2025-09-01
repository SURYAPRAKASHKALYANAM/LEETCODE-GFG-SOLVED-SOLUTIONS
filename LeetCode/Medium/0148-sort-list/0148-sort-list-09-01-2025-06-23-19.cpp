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
    ListNode* sortList(ListNode* head) {
        ListNode *t;
        t=head;
        int a[50000],n=0;
        while(t!=NULL)
        {
            a[n]=t->val;
            t=t->next;
            n++;
        }
        n--;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=n-1-i;j++)
            {
                if(a[j]>a[j+1])
                {
                    int x=a[j];
                    a[j]=a[j+1];
                    a[j+1]=x;
                }
            }
        }
        t=head;
        n=0;
        while(t!=NULL)
        {
            t->val=a[n];
            n++;
            t=t->next;
        }
        return head;
    }
};