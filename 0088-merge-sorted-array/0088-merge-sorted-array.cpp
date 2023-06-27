class Solution
{
    public:
        void swapifGreater(vector<int> &arr1, vector<int> &arr2, int m, int n)
        {
            if (arr1[m] > arr2[n]) swap(arr1[m], arr2[n]);
        }
    void merge(vector<int> &arr1, int m, vector<int> &arr2, int n)
    {
       	// Write your code here.
        int len = m + n;
        int gap = (len / 2) + (len % 2);
        while (gap > 0)
        {
            int left = 0, right = left + gap;
            while (right < len)
            {
                if (left < m && right >= m) swapifGreater(arr1, arr2, left, right - m);
                else if (left >= m) swapifGreater(arr2, arr2, left - m, right - m);
                else swapifGreater(arr1, arr1, left, right);
                left++;
                right++;
            }
            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
        for (int i = 0; i < n; i++)
        {
            arr1[m + i] = arr2[i];
        }
    
    }
};