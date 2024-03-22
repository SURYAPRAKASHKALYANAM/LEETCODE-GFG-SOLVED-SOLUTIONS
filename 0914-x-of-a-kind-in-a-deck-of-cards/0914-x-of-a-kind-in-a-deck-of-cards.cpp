class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> m;
        for(auto i:deck) m[i]++;
        int gs=-1;
        for(auto i:m) 
        {
            if(gs==-1) gs=i.second;
            else gs=__gcd(gs,i.second);
        }
        return (gs==1)? false:true;
    }
};