class Solution {
public:
    string reverseWords(string s) 
    {
        int start=s.size()-1,end=s.size()-1;
        string ans="";
        while(start>=0 || end>=0)
        {
            if(end<0 || start<0) break;
            while(end>=0 && s[end]==' ') end--;
            start=end;
            while(start>=0 && s[start]!=' ') start--;
            for(int i=start+1;i<=end&& s[i]!=' ';i++) ans+=s[i];
            if(end-start>=1) ans+=' ';
            end=start-1;
        }
        ans.pop_back();
       return ans; 
    }
};