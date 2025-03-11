class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int max_cnt=1,cnt=1;
        for(int i=1;i<nums.size();i++)
        {
            cnt++;
            if(nums[i]>nums[i-1]) max_cnt=max(max_cnt,cnt);
            else cnt=1;
        }
        return max_cnt;
    }
};