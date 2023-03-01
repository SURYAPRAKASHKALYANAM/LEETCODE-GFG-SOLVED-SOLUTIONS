class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n=arr.size();
        bool f=0;
        for(int i=0;i<n-1;i++)
        {
            if(f==0)
            {
                if(arr[i]>arr[i+1]) swap(arr[i],arr[i+1]);
                f=1;
                continue;
            }
            else
            {
                if(arr[i]<arr[i+1]) swap(arr[i],arr[i+1]);
                f=0;
            }
        }
        vector<int> ans(arr.begin(),arr.end());
        return ans;
        
    }
};