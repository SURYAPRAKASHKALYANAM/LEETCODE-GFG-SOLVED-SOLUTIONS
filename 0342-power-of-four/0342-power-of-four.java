class Solution {
    public boolean isPowerOfFour(int n) 
    {
        if(n==1 || (n&n-1)==0 && n>0)
        {
            int c=0;
            while(n!=0)
            {
                c++;
                n=n>>1;
            }
            if(c%2==1) return true;
            return false;
        }
        return false;
    }
}