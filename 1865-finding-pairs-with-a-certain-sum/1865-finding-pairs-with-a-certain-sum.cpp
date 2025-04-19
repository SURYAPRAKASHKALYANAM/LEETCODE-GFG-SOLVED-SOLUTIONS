class FindSumPairs {
public:
    unordered_map<int, int> c1, c2;
    vector<int> n2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n2 = nums2;
        for (int i : nums1)
            c1[i]++;
        for (int i : n2)
            c2[i]++;
    }

    void add(int index, int val) {
        c2[n2[index]]--;
        n2[index] += val;
        c2[n2[index]]++;
    }

    int count(int tot) {
        int cnt = 0;
        for (auto i : c1) {
            cnt += i.second * c2[tot - i.first];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */