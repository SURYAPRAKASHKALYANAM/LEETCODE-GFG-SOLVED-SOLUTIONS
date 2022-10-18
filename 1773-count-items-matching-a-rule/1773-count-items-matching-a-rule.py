class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        c=0
        if (ruleKey=='type'):
            i=0
        elif (ruleKey=='color'):
            i=1
        elif (ruleKey=='name'):
            i=2
        for j in items:
            if ruleValue==j[i]:
                c+=1
        return c        
    
   

          
        
        
                
        