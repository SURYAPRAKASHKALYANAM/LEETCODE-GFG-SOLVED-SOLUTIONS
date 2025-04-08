class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int minops = 0, n = nums.size();
        sort(begin(nums), end(nums));
        int prev = nums[0];
        for (int i = 1; i < n; i++) {
            if(nums[i]<=prev){
                minops+=(prev+1-nums[i]);
                nums[i]=prev+1;
            }
            prev=nums[i];
        }
        return minops;
    }
};