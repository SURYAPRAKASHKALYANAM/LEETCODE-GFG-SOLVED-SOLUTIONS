class Solution
{
    public:
        vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
        {
            unordered_map<int, int> m;
            for (int i = 0; i < arr2.size(); i++) m[arr2[i]] = i + 1;
            sort(arr1.begin(), arr1.end(), [& ](int x1, int x2)
            {
                int ind1 = m[x1] ? m[x1] : INT_MAX;
                int ind2 = m[x2] ? m[x2] : INT_MAX;
                if (ind1 != ind2) return ind1 < ind2;
                return x1 < x2;
	});
            return arr1;
        }
};