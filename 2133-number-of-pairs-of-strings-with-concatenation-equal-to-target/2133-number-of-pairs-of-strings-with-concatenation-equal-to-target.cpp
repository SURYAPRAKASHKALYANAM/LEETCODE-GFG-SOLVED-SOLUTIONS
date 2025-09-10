class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int cnt = 0;
        int len = target.size();
        unordered_map<string, int> cnts;
        for (auto s : nums) {
            if (target.ends_with(s)) {
                string pre = target.substr(0, len - s.size());
                cnt += cnts[pre];
            }
            if(target.starts_with(s)){
                string suff = target.substr(s.size(), len);
                cnt += cnts[suff];
            }
            cnts[s]++;
        }
        return cnt;
    }
};