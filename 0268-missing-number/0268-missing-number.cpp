class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int s=accumulate(nums.begin(),nums.end(),0);
        int k=nums.size();
        return (k*(k+1)/2)-s;
    }
};