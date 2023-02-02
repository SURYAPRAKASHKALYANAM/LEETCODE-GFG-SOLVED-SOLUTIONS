class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    //     sort(points.begin(),points.end(),[this] (vector<int> a, vector<int> b) {
    // return compare(a, b); });
        priority_queue<double> q;
        unordered_map<double,vector<vector<int>>> m;
        double d,id;
        for(auto i:points)
        {
            d=pow((pow(i[0],2)+pow(i[1],2)),0.5)/1.0;
            m[d].emplace_back(i);
            q.push(d);
        }
        int r=points.size()-k;
        while(r)
        {
            id=q.top();
            if(m[id].size())
            {
                m[id].pop_back();
                r--;
            }
            else
            {
                q.pop();
                // r--;
            }
            
        }
        points.clear();
        while(!q.empty())
        {
            id=q.top();
            while(m[id].size()!=0)
            {
                points.emplace_back(m[id].back());
                m[id].pop_back();
            }
            q.pop();
        }
        return points;
    }
};