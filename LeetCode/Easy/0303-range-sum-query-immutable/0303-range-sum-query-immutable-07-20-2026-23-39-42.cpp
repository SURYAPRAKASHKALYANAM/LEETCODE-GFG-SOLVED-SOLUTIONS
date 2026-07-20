class NumArray {
public:
    vector<int> v;
    NumArray(vector<int>& nums)
    {
        for(int i=0;i<nums.size();i++)
            v.emplace_back(nums[i]);
        
    }
    
    int sumRange(int l, int r) 
    {
        return accumulate(v.begin()+l,v.begin()+r+1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */