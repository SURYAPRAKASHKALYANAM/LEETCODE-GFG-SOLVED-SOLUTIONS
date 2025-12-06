class Solution {
public:
    int reverse(int n) {
        int revNum = 0;
        while (n % 10 == 0)
            n /= 10;
        while (n) {
            revNum = (revNum * 10) + (n % 10);
            n /= 10;
        }
        return revNum;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, set<int>> posIdx;
        for (int i = 0; i < nums.size(); i++)
            posIdx[nums[i]].insert(i);
        int minObs = 1e9;
        for (int i = 0; i < nums.size(); i++) {
            int revNum = reverse(nums[i]);
            if (posIdx[revNum].size()) {
                auto it = posIdx[revNum].upper_bound(i);
                if (it != posIdx[revNum].end())
                    minObs = min(minObs, *it - i);
            }
        }
        return minObs == 1e9 ? -1 : minObs;
    }
};