class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> m;
        int sum=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==goal) count++;
            if(m.find(sum-goal)!=m.end())
            {
                int j=m[sum-goal]+1;
                int cnt=1;
                while(j<nums.size() && nums[j++]==0 && j<=i) cnt++;
                count+=cnt;
            }
            if(m.find(sum)==m.end()) m[sum]=i;
        }
        return count;
        
    }
};