class Solution
{
    public:
        void mergesort(vector<int> &arr, int low, int mid, int high)
        {
            int left = low, right = mid + 1;
            vector<int> temp;
            while (left <= mid && right <= high)
            {
                if (arr[left] <= arr[right])
                {
                    temp.emplace_back(arr[left++]);
                }
                else
                {
                    temp.emplace_back(arr[right++]);
                }
            }
            while (left <= mid)
            {
                temp.emplace_back(arr[left++]);
            }
            while (right <= high)
            {
                temp.emplace_back(arr[right++]);
            }
            for (int i = low; i <= high; i++) arr[i] = temp[i - low];
        }
    long long countpairs(vector<int> &arr, int low, int mid, int high)
    {
        long long cnt = 0;
        int right = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && (long long)arr[i] >(long long) 2 *arr[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    long long merge(vector<int> &arr, int low, int high)
    {
        long long cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2;
        cnt += merge(arr, low, mid);
        cnt += merge(arr, mid + 1, high);
        cnt += countpairs(arr, low, mid, high);
        mergesort(arr, low, mid, high);
        return cnt;
    }
    int reversePairs(vector<int> &nums)
    {
        return (int) merge(nums, 0, nums.size() - 1);
    }
};