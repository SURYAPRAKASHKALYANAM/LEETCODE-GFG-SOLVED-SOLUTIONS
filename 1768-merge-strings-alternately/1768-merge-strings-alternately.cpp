class Solution {
public:
    string mergeAlternately(string word1, string word2)
    {
        int len1=0,len2=0,f=1;
        string ans="";
        for(;len1<word1.size()&&len2<word2.size();)
        {
            if(f)
            {
                ans+=word1[len1++];
                f=0;
            }
            else
            {
                ans+=word2[len2++];
                f=1;
            }
        }
        for(;len1<word1.size();) ans+=word1[len1++];
        for(;len2<word2.size();) ans+=word2[len2++];
        return ans;
    }
};