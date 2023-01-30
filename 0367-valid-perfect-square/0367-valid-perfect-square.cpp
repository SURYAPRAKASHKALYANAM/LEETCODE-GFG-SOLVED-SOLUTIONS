class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        if(num==1) return 1;
        long long low=1,high=(num/2),mid;
        while(low<=high)
        {
            mid=(low+high)>>1;
            if(mid*mid==num) return 1;
            if(mid*mid>num) high=mid-1;
            else low=mid+1;
        }
        return 0;
    }
};