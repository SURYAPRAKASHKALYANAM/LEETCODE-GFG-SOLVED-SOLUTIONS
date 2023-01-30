class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) 
    {
        long long  ways=0;
        while(total>=0)
        {
            ways+=(total/cost2)+1;
            total-=cost1;
        }
        return ways;
        
    }
};