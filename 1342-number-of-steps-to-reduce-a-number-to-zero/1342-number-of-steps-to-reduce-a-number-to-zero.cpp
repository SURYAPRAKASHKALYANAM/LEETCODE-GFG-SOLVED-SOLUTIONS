class Solution {
public:
    int numberOfSteps(int num) {
        if(!num) return 0;
        int cnt=1;
        while(num>1)
        {
            if(num&1) cnt+=2,num/=2;
            else cnt++,num/=2;
        }
        return cnt;
    }
};