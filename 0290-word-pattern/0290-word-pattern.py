class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        l=s.split(' ')
        d={}
        s=set([])
        if(len(pattern)!=len(l)):
            return False
        for i in range(len(pattern)):
            a,b=pattern[i],l[i]
            if(list(d.keys()).count(a)!=0):
                if(d[a]!=b):
                    return False
            else:
                if(list(s).count(b)!=0):
                    return False
                d[a]=b
                s.add(b)
        return True        
                
            
        
        