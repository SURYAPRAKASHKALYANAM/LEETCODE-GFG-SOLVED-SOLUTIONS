class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        if(num%3==0)
        {
            ans.emplace_back((num/3)-1);
            ans.emplace_back(num/3);
            ans.emplace_back((num/3)+1);
        }
        return ans;
    }
};