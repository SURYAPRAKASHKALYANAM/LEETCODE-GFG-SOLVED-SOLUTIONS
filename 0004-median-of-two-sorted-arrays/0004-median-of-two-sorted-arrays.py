class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1.extend(nums2)
        nums1.sort()
        k=len(nums1)
        if k%2==0:
            return float((nums1[int((k-1)/2)]+nums1[int((k+1)/2)])/2)
        else:
            return float(nums1[int(k/2)])
        