class Solution {
public:
    long long minEnd(int n, int x) {
        long long a=x;
        while(--n>0)  a=x|(a+1);
        return a;
    }
};