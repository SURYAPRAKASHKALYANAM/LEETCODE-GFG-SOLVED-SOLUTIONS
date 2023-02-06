class Solution
{
    public:
        int xorAllNums(vector<int> &nums1, vector<int> &nums2)
        {
            int x =0;
//             for (int i = 0; i < nums1.size(); i++)
//             {
//                 for (int j = 0; j < nums2.size(); j++)
//                 {
                    
//                     x = x ^ (nums1[i] ^ nums2[j]);
//                 }
//             }
            if((nums1.size()&1) && (nums2.size()&1))
            {
                for(auto i:nums1) x=x^i;
                for(auto j:nums2) x=x^j;
                return x;
            }
            else if(nums1.size()&1)
            {
                 for(auto j:nums2) x=x^j;
                 return x;                  
            }
            else if(nums2.size()&1)
            {
                for(auto j:nums1) x=x^j;
                return x; 
            }
            return x;
        }
};