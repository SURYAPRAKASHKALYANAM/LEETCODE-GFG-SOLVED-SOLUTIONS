class MyCalendar {
public:
    vector<vector<int>> nums;
    MyCalendar() 
    {
        
    }
    bool book(int start, int end)
    {
        vector<int> v;
        v.emplace_back(start);
        v.emplace_back(end);
        int n=nums.size();
        int c=0;
        if(n==0)
        {
            nums.emplace_back(v);
            return true;
        }
        else
        {
            for(int i=0;i<nums.size();i++)
            {
            if( (start<nums[i][0] && end<=nums[i][0]) || (start>nums[i][0]) && start>=nums[i][1])
                    c++;
            }
            
        }
        if(c==n)
        {
            nums.emplace_back(v);
            return true;
        }
        else
            return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */