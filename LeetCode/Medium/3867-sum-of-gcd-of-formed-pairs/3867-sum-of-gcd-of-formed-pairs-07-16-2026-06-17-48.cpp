class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long sum = 0 ;
        int maxi = 0;
        int len = nums.size();
        vector<int> temp(len);
        for(int i=0;i<len;i++){
            maxi = max(maxi,nums[i]);
            temp[i] = __gcd(nums[i],maxi);
        }
        sort(temp.begin(),temp.end());
        int start = 0 , end = len-1;
        while(start<end){
            sum+=(1LL*__gcd(temp[start],temp[end]));
            start++;end--;
        }
        return sum;
    }
};