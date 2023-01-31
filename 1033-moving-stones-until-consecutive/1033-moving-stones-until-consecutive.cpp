class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) 
    {
        vector<int> nums={a,b,c};
        sort(nums.begin(),nums.end());
        if(nums[0]+1==nums[1] && nums[1]+1==nums[2]) return {0,0};
        if(nums[1]-nums[0]-1<=1 || nums[2]-nums[1]-1<=1) return {1,nums[2]-nums[0]-2};
        else return {2,nums[2]-nums[0]-2};
        
    }
};