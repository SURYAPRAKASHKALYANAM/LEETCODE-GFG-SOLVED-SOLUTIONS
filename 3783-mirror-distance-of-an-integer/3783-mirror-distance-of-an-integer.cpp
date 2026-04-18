class Solution {
public:
    int reverse(int n){
        int newn = 0;
        while(n){
            newn = newn*10 + (n%10);
            n/=10;
        }
        return newn;
    }
    int mirrorDistance(int n) {
        return abs(n-reverse(n));
    }
};