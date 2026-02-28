class Solution:
    def concatenatedBinary(self, n: int) -> int:
        s=''
        for x in range(1,n+1):
            b=0
            product=1
            while(x!=0):
                r=x%2
                b+=r*product
                x=x//2
                product*=10
            s+=str(b)    
        return int(s,2)%(10**9+7)
                
            
        