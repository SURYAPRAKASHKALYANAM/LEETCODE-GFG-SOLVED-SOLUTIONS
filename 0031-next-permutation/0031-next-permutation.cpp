class Solution
{
    public:
        void nextPermutation(vector<int> &nums)
        {
           	// next_permutation(nums.begin(),nums.end());
           	//Implementation

            int index = -1, n = nums.size();
           	//step1:find break index
            for (int i = n - 2; i >= 0; i--)
            {
                if (nums[i] < nums[i + 1])
                {
                    index = i;
                    break;
                }
            }
           	// if no break index
            if (index == -1)
            {
                reverse(nums.begin(), nums.end());
                return;
            }
           	//step 2:swap index value with next greater element
            for (int i = n - 1; i > index; i--)
            {
                if (nums[i] > nums[index])
                {
                    swap(nums[i], nums[index]);
                    break;
                }
            }
           	//step3: reverse remaining array
            reverse(nums.begin() + index + 1, nums.end());
            return;
        }
};