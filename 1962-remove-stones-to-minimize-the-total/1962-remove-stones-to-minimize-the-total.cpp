class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
       priority_queue<int> q(piles.begin(),piles.end());
        int ans=0,r;
        while(k--)
        {
            r=q.top();
            q.pop();
            q.push(r-(r/2));
            
        }
        while(!q.empty())
        {
            ans+=q.top();
            q.pop();
        }
        return ans;
    }
    Solution()
    {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
};