class Solution {
public:
    int partitionString(string s) 
    {
        int reach=0;
        unordered_map<char,int> m;
        for(auto i=0;i<s.size();i++)
        {
            if(m[s[i]]==0) m[s[i]]=1;
            else
            {
                reach+=1;
                i--;
                m.clear();
            }
        }
        reach++;
        return reach;
    }
};