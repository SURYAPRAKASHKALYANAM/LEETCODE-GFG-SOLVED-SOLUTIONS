class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string div="";
        int l=__gcd(str1.size(),str2.size());
        for(int i=0;i<l;i++) div+=str1[i];
        for(int i=0;i<str1.size();)
        {
            for(int j=0;j<l;j++)
            {
                if(str1[i++]!=div[j]) return "";
            }
        }
        for(int i=0;i<str2.size();)
        {
            for(int j=0;j<l;j++)
            {
                if(str2[i++]!=div[j]) return "";
            }
        }
        return div;
    }
};