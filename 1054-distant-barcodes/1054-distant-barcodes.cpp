class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        priority_queue<pair<int,int>> q;
        unordered_map<int,int> counts;
        for(auto i:barcodes) counts[i]++;
        for(auto i:counts) q.push({i.second,i.first});
        vector<int> ans;
        while(!q.empty())
        {
            int fc=q.top().first,ele=q.top().second,sc=-1,sele;
            ans.push_back(ele);
            q.pop();
            if(!q.empty())  sc=q.top().first,sele=q.top().second,ans.emplace_back(sele),q.pop();
            if(sc!=-1 && sc-1>0) q.push({sc-1,sele});
            if(fc-1>0)q.push({fc-1,ele});
        }
        return ans;
    }
};