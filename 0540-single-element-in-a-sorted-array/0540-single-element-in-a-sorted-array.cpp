class Solution {
public:
    int singleNonDuplicate(vector<int>& a) 
    {
        int low=0,mid=0,high=a.size()-1;
        if(high==0) return a[0];
        while(low<=high)
        {
            mid=(low+high)/2;
            cout<<mid<<" ";
            if(mid==0 && a[0]!=a[1]) return a[0];
            else if(a[mid-1]!=a[mid] && a[mid+1]!=a[mid]) return a[mid];
            else if(a[mid+1]==a[mid])
            {
                if((high-mid+1)%2==0) high=mid-1;
                else low=mid+2;
            }
            else if(a[mid-1]==a[mid])
            {
                if((mid-low)%2==0) high=mid-2;
                else low=mid+1;
            }
        }
        return low;
        
    }
};