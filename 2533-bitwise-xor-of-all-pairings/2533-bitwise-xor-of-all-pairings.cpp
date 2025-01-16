class Solution
{
    public:
        int xorAllNums(vector<int> &nums1, vector<int> &nums2)
        {
            int n1 = nums1.size(), n2 = nums2.size();
            int xor1 = accumulate(nums1.begin(), nums1.end(), 0, bit_xor < > ()),
                xor2 = accumulate(nums2.begin(), nums2.end(), 0, bit_xor < > ());
            return (n1 & 1) ? ((n2 & 1) ? xor1 ^ xor2 : xor2) : ((n2 & 1) ? xor1 : 0);
        }
};