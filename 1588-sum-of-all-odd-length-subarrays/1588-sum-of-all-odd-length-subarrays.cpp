class Solution {
public:
    int ts=0;
    void summ(vector<int>& arr,int start,int end)
    {
        if(end==arr.size()) return ;
        if(start>end) return summ(arr,0,end+1);
        else
        {
            if((end-start+1)%2!=0)
            {
                int s=0;
                for(int i=start;i<end;i++) s+=arr[i];
                s+=arr[end];
                ts+=s;
            }
            return summ(arr,start+1,end);
        }
     }
    int sumOddLengthSubarrays(vector<int>& arr) {
        summ(arr,0,0);
        return ts;
    }
};