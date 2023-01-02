class Solution {
public:
    string getPermutation(int n, int k)
    {
        string a="";
        vector<int> ns;
        int f=1;
        for(int i=1;i<n;i++)
        {
            f*=i;
            ns.emplace_back(i);
        }
        ns.emplace_back(n);
        k--;
        while(true)
        {
            a+=to_string(ns[k/f]);
            ns.erase(ns.begin()+k/f);
            if(ns.size()==0) break; 
            k=k%f;
            f=f/ns.size();
        }
        return a;
        
    }
};