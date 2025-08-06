class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int start = 0 ,end = len-1,mid;
        int minEle = 1e4;
        while(start<=end){
            mid = start + (end-start)/2;
            // cout<<start<<" "<<mid<<" "<<end<<endl;
            if(nums[mid]<=nums[end]){
                minEle = min(minEle,nums[mid]);
                // cout<<minEle<<"\n";
                end=mid-1;
            } else{
                // minEle = min(minEle,nums[mid+1]);
                start=mid+1;
            }
        }
        return minEle;
    }
};