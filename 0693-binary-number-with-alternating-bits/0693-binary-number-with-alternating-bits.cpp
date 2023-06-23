class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool flag=0,oddf=0,cf=0;
        if(n&1)
        {
            oddf=1;
            flag=1;
            cf=1;
        }
        while(n>=1)
        {
            if(oddf)
            {
                if((n%2)==cf)
                {
                    cf=!cf;
                    n=n/2;
                }
                else return false;
            }
            else
            {
                if((n%2)==cf)
                {
                    cf=!cf;
                    n=n/2;
                }
                else return false;
            }
        }
        return true;
    }
};