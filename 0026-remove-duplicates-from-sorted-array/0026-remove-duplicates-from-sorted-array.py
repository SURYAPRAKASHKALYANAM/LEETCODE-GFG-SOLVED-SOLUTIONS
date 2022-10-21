class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        nums.sort()
        for i in set(nums):
            if nums.count(i)>1:
                while(nums.count(i)!=1):
                    nums.remove(i)
        return len(nums)            
                
        