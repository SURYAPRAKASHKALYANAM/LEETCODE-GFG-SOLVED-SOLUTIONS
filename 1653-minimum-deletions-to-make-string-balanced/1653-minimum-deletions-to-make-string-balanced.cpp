class Solution
{
    public:
        int minimumDeletions(string s)
        {
            vector<int> a(s.size()+1, 0);
            int bbefore=0;
            for (int i = 0; i < s.size(); i++)
            {
               if(s[i]=='a')
               {
                    a[i+1]=min(a[i]+1,bbefore);
               }
               else
               {
                   a[i+1]=a[i];
                   bbefore++;
               }
            }
            return a[s.size()];
        }
};