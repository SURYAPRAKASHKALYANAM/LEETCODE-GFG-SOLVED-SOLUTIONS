class Solution {
public:
    int halveArray(vector<int>& nums) 
    {
        double sum=accumulate(nums.begin(),nums.end(),0.0),s=sum,r;
        priority_queue<double> q(nums.begin(),nums.end());
        int c=0;
        while(s>sum/2.0)
        {
            r=q.top();
            s-=(r/2.0);
            q.pop();
            q.push(r/2.0);
            c++;
        }
        return c;
        
    }
};