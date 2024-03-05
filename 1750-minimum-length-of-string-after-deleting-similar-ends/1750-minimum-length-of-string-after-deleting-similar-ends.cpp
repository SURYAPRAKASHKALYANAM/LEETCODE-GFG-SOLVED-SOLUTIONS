class Solution {
public:
    int minimumLength(string s) {
        int begin=0,end=s.size()-1;
        while(begin<end)
        {
            if(s[begin]==s[end])
            {
                for(;begin+1<s.size();)
                {
                    if(s[begin]==s[begin+1]) begin++;
                    else break;
                }
                for(;end-1>=0;)
                {
                    if(s[end]==s[end-1]) end--;
                    else break;
                }
                begin++;
                end--;
            }
            else break;
        }
        return max(0,end-begin+1);
    }
};