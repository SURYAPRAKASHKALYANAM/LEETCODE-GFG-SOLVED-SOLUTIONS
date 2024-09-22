class Solution {
public:
    int findgap(long start,long end,long n)
    {
        int gap=0;
        while(start<=n)
        {
            gap+=min(n+1,end)-start;
            start*=10;
            end*=10;
        }
        return gap;
    }
    int findKthNumber(int n, int k) {
        long start=1,have=1;
        while(have<k)
        {
            int needed=findgap(start,start+1,n);
            if(needed+have <= k)
            {
                have+=needed;
                start++;
            }
            else {
                have++;
                start*=10;
            }
        }
        return (int)start;
    }
};