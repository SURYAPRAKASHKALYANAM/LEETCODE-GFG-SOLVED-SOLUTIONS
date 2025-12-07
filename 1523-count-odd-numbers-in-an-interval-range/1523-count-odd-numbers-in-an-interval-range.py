class Solution:
    def countOdds(self, low: int, high: int) -> int:
        c=0
        i1,i2=(low%2==0),(high%2==0)
        if not i1 and not i2:
            return int((high-low)/2)+1
        if i1 and i2:
            return int((high-low)/2)
        if not i1 and i2:
            return int((high-low)/2)+1
        else:
            return int((high-low)/2)+1
            
        