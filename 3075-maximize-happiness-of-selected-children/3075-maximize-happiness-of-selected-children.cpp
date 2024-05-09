class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0;
        priority_queue<int> q(happiness.begin(),happiness.end());
        int curr=0;
        while(k--)
        {
            if(q.top()-curr>0) ans+=(q.top()-curr);
            else break;
            curr++;
            q.pop();
        }
        return ans;
    }
};