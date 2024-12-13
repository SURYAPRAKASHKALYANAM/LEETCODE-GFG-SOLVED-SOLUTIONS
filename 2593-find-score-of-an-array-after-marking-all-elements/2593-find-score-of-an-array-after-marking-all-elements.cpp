class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans=0;
        int pos,len=0,ele;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        unordered_map<int,int> m;
        for(auto i=0;i<nums.size();i++) q.push({nums[i],i});
        while(len<nums.size())
        {
            if(!q.empty())
            {
                auto it=q.top();q.pop();
                ele=it.first,pos=it.second;
                if(!m[pos])
                {
                    m[pos]=1;
                    ans+=ele;
                    len++;
                    if( (pos-1) >= 0 && !m[pos-1]) m[pos-1]=1,len++;
                    if( (pos+1) <nums.size() && !m[pos+1]) m[pos+1]=1,len++;
                }
            }
        }
        return ans;
    }
};