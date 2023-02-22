class Solution {
public:
    int maxArea(vector<int>& nums)
    {  int m=0,i=0,j=nums.size()-1;
        while(i<j)
        {
            m=max(m,min(nums[i],nums[j])*(j-i));
            if(nums[i]<nums[j]) i++;
            else j--;
        }
         return m;
    }
    
};