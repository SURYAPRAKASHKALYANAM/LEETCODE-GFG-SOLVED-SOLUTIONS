class Solution
{
    public:

    vector<int> successfulPairs(vector<int> &spells, vector<int> &pot, long long maxtarget)
    {
        sort(pot.begin(), pot.end());
        vector<int> pairs(spells.size());
        int p=pot.size();
        for (int i = 0; i < spells.size(); i++)
        {
            int k=spells[i];
            int low = 0, high = p - 1, mid;
            while (low <= high)
            {
                mid = low + (high - low) / 2;
                long long product = (long long)k * (long long)pot[mid];
                if (product >= maxtarget) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            pairs[i] =p - low;
        }
        return pairs;
    }
};