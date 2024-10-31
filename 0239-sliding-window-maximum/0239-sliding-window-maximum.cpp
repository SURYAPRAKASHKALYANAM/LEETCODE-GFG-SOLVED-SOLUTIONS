class Solution
{
    public:
        vector<int> maxSlidingWindow(vector<int> &nums, int k)
        {
            priority_queue<pair<int, int>> q;
            for (int i = 0; i < k; i++) q.push({nums[i],i});
            vector<int> ans;
            int ele = q.top().first, index = q.top().second;
            ans.emplace_back(ele);
            int left = 0, right = k;
            while (right < nums.size())
            {
                left++;
                q.push({nums[right],right++});
                ele = q.top().first, index = q.top().second;
                while (!q.empty() && index < left) 
                {
                    q.pop();
                    ele = q.top().first, index = q.top().second;
                }
                ans.emplace_back(ele);
            }
            return ans;
        }
};