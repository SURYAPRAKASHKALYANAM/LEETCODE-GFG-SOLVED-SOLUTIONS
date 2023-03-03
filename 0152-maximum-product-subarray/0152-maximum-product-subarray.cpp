class Solution
{
    public:
        int maxProduct(vector<int> &nums)
        {
            int leftmax=INT_MIN,rightmax=INT_MIN,prod=1;
            bool zero=0;
            for(auto i:nums)
            {
                prod*=i;
                if(!i)
                {
                    prod=1;
                    zero=1;
                    continue;
                }
                leftmax=max(prod,leftmax);
            }
            prod=1;
            for(int j=nums.size()-1;j>=0;j--)
            {
                prod*=nums[j];
                if(!nums[j])
                {
                    prod=1;
                    zero=1;
                    continue;
                }
                rightmax=max(prod,rightmax);
            }
            if(zero) return max(0,max(leftmax,rightmax));
            return max(leftmax,rightmax);
        }
};