class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int minops = 0, n = nums.size();
        // O (nlogn)
        // sort(begin(nums), end(nums));
        // int prev = nums[0];
        // for (int i = 1; i < n; i++) {
        //     if(nums[i]<=prev){
        //         minops+=(prev+1-nums[i]);
        //         nums[i]=prev+1;
        //     }
        //     prev=nums[i];
        // }
        // O(N)
        vector<int> counts(n + *max_element(begin(nums), end(nums)));
        for (auto i : nums)
            counts[i]++;
        for (int i = 0; i < counts.size(); i++) {
            int remdup = counts[i] - 1;
            if (remdup > 0) {
                counts[i + 1] += remdup;
                minops += remdup;
            }
        }
        return minops;
    }
};