class Solution {
public:
    int common(int ma,int n)
    {
        int maxi=max(ma,n),mini=min(ma,n);
        while(maxi!=mini)
        {
            if(maxi>mini) maxi/=2;
            else mini/=2;
        }
        return 2*(int)log2(mini);
        
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) 
    {
        vector<int> ans;
        for(auto i:queries)
        {
            if((int)(max(i[0],i[1])/2)==min(i[0],i[1])) ans.emplace_back(2);
            else
            {
                int minus=common(i[0],i[1]);
                ans.emplace_back((int)log2(i[0])+(int)log2(i[1])+1-minus);
            }
        }
        return ans;
    }
};