class Solution {
public:
    int sum(int n)
    {
        return n*(n+1)/2;
    }
    int pivotInteger(int n) 
    {
        int tot=sum(n);
        for(int i=1;i<=n;i++)
        {
            if(sum(i)==tot-sum(i-1)) return i;
        }
        return -1;         
    }
};