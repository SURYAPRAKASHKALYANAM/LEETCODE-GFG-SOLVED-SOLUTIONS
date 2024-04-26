class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        int temp=k;
        for(int i=1;i<=n;i++) q.push(i);
        while(q.size()>1)
        {
            int curr=q.front();
            q.pop();
            temp--;
            if(temp!=0)
            {
                q.push(curr);
            }
            else temp=k;
        }
        return q.front();
    }
};