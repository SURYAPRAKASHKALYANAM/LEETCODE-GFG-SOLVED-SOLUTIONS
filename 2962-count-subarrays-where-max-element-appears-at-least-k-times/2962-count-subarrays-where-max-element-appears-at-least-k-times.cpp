class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_ele=*max_element(nums.begin(),nums.end());
        int count=0,left=0,right=0,n=nums.size();
        long long cnt=0;
        while(right<n)
        {
            if(nums[right]==max_ele) count++;
            while(count==k)
            {
                if(nums[left]==max_ele) count--;
                left++;
            }
            cnt+=left;
            right++;
        }
        return cnt;
        
    }
};