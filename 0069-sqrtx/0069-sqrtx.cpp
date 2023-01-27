class Solution {
public:
    int mySqrt(int x) 
    {
       double low=1,high=x;
       while(high-low>1e-5)
       {
           double mid=(low+high)/2.0;
           if((double)mid*mid < x) low=mid;
           else high=mid;
       }
        return high;
        
    }
};