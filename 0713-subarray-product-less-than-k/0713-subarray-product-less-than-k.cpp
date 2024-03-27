class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int cnt=0;
        int i=0,j=0,product=1;
        while(j<nums.size())
        {
            product*=nums[j];
            while(product>=k)
            {
                product=product/nums[i];
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
};