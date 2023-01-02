class Solution {
public:
    string getPermutation(int n, int k)
    {
        string a="";
        for(int c=1;c<=n;c++) a+=to_string(c);
        while(k!=1)
        {
            k--;
            next_permutation(a.begin(),a.end());
        }
        
        
        return a;
        
    }
};