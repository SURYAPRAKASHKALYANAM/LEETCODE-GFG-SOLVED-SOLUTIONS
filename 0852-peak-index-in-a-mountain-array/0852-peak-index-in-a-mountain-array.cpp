class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        long long int low=0,high=arr.size()-1,mid;
        while(low<=high)
        {
            mid=(low+high)>>1;
            if(mid==0)
            {
                if(arr[mid]<arr[mid+1]) low=mid+1;
                continue;
            }
            if(mid==arr.size()-1)
            {
                if(arr[mid-1]>arr[mid]) high=mid-1;
                continue;
            }
            if(mid>0 && mid<arr.size()-1 && arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]) return mid;
            else if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]) low=mid+1;
            else if( arr[mid-1]>arr[mid] && arr[mid]>arr[mid+1]) high=mid-1;     
        }
        return 0;
        
    }
};