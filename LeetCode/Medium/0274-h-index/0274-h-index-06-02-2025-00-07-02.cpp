class Solution {
public:
    int hIndex(vector<int>& cit) 
    {
        int h=0;
        sort(cit.begin(),cit.end());
        int s=cit.size();
        for(int i=0;i<s;i++)
        {
            if(s-i<=cit[i]) h=max(h,s-i);
        }
        return h;
    }
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
};