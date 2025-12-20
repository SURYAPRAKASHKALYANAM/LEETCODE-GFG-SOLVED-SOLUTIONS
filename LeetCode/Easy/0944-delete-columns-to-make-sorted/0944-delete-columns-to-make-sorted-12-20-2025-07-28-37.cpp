class Solution {
public:
    bool isnotsorted(string s)
    {
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]>s[i+1]) return true;
        }
        return false;
    }
    int minDeletionSize(vector<string>& strs) 
    {
        vector<string> index_string(strs[0].size(),"");
        for(int i=0;i<strs.size();i++)
        {
            for(int j=0;j<strs[0].size();j++)
            {
                index_string[j]+=strs[i][j];
            }
        }
        int c=0;
        for(auto i:index_string)
        {
            if(isnotsorted(i)) c+=1;
        }
        return c;
    }
};