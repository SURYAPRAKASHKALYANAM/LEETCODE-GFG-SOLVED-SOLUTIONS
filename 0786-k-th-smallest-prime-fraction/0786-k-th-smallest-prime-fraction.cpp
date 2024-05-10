class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<float,pair<int,int>>> q;
        int l=0;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                q.push({(float)((float)arr[i]/(float)arr[j]),{arr[i],arr[j]}});
                l++;
            }
        }
        while(l>k)
        {
            q.pop();
            l--;
        }
        return {q.top().second.first,q.top().second.second};
        
    }
};