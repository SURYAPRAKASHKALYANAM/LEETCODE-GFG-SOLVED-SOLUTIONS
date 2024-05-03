class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        l1=version1.split('.')
        l2=version2.split('.')
        l1=list(map(int,l1))
        l2=list(map(int,l2))
        len_l1=len(l1)
        len_l2=len(l2)
        if len_l1<len_l2:
            while(len_l1<len_l2):
                l1.append(0)
                len_l1+=1
        elif len_l2<len_l1:
            while(len_l2<len_l1):
                l2.append(0)
                len_l2+=1
        for i in range(len_l1):
            if l1[i]>l2[i]:
                return 1
            elif l1[i]<l2[i]:
                return -1
        return 0
        