class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left=0,right=height.size()-1;
        int maxi=INT_MIN;
        while(left<right)
        {
            if(height[left]>height[right])
            {
                maxi=max(maxi,(right-left)*height[right]);
                right--;
            }
            else
            {
                 maxi=max(maxi,(right-left)*height[left]);
                left++;
            }
        }
        return maxi;
    }
};