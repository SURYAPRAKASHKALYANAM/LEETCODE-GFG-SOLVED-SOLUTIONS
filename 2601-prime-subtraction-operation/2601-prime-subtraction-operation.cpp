class Solution {
public:
    int find_prime(int n)
    {
        if(n==1 || n==2) return 0;
        while(n--)
        {
            bool f=1;
            for(int i=2;i*i<=n;i++)
            {
                if(n%i==0){ f=0; break;}
            }
            if(f) return n;
        }
        return 0;
    }
    bool primeSubOperation(vector<int>& nums) {
        nums[0]-=find_prime(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            int prime=find_prime(nums[i]);
            while(prime &&  (nums[i]-prime) <= nums[i-1])   prime=find_prime(prime);
            nums[i]-=prime;
            if(nums[i]>nums[i-1]) continue;
            else return false;
        }
        return true;
    }
};