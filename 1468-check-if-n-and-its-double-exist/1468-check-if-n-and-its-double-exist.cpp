class Solution
{
    public:
        bool checkIfExist(vector<int> &arr)
        {
            sort(arr.begin(), arr.end());
            int st = 0, n = arr.size();
            while (st < n - 1)
            {
                int target = 2 *arr[st++];
                int start = 0, end = n - 1;
                while (start <= end)
                {
                    int mid = start + ((end - start) / 2);
                    if (arr[mid] == target && mid!=st-1) return true;
                    if (arr[mid] > target) end = mid - 1;
                    else start = mid + 1;
                }
            }
            return false;
        }
};