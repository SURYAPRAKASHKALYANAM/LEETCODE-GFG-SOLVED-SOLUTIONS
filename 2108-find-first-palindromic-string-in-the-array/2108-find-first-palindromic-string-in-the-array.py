class Solution:
    def helper(self,string):
        if (string==string[::-1]):
            return True
        return False
    def firstPalindrome(self, words: List[str]) -> str:
        for i in words:
            if(self.helper(i)):
                return i;
        return "";
        