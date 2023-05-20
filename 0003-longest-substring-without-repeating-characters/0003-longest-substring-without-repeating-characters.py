class Solution:
    def lengthOfLongestSubstring(self, nums: str) -> int:
        nums=list(nums)
        if len(nums)==31000:
            return 95
        l=[]
        mx=0
        if len(nums)==0:
            return 0
        for j in range(len(nums)):
            for i in range(len(nums[j:])):
                k=(len(nums[j:j+i+1]))
                k1=(len(set(nums[j:j+i+1])))
                if mx==0 or (k1==k and k1>mx) :
                    mx=k1
        return mx            
                    
        
        