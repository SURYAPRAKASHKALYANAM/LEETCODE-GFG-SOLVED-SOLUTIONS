class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        i=1
        k=set(nums)
        while( i in k ):
            i+=1
        return i    
        