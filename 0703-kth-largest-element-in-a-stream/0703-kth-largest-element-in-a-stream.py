class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.l=[]
        self.l.append(k)
        self.l.append(nums)

    def add(self, val: int) -> int:
        self.l[1].append(val)
        self.l[1].sort()
        return self.l[1][len(self.l[1])-self.l[0]]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)