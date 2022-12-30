class Solution {
public:
    int lastStoneWeight(vector<int>& s) 
    {
        if(s.size()==1) return s[0];
        sort(s.begin(),s.end());
        int k,q;
        while(true)
        {
            if(s.size()<=1) return s[0];
            else
            {
                k=s.back();
                s.pop_back();
                q=s.back();
                s.pop_back();
                if(k==q && s.size()==0) return 0;
                s.emplace_back(abs(k-q));
                sort(s.begin(),s.end());
                cout<<s.size()<<" "<<s[0];
            }
        }
        return 0; 
    }
};