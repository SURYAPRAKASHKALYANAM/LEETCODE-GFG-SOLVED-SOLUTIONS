class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        unordered_map<int,int> m;
        for(auto i:arr) m[i]++;
        for(int i=1;;i++)
        {
            if(m[i]==0) k--;
            if(k==0) return i;
        }
        return -1;
    }
};