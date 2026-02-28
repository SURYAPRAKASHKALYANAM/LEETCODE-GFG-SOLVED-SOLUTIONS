class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        sol=[]
        if len(nums)==1 or len(nums)==0:
            return sol
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                for k in range(j+1,len(nums)):
                    if nums[i]+nums[j]+nums[k]==0:
                        l=[]
                        l.append(nums[i])
                        l.append(nums[j])
                        l.append(nums[k])
                        l.sort()
                        if l not in sol:
                            sol.append(l)
        return sol