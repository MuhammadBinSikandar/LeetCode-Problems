class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merged = nums1 + nums2
        merged.sort()
        length = len(merged)
        if length % 2 == 1:
            return float (merged[length//2])
        else:
            return (float(merged[length//2-1])+float(merged[length//2]))/2.0
        