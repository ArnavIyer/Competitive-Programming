class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        num = nums[0]
        ct = 0
        for i in nums:
            if i == num:
                ct += 1
            else:
                ct -= 1
                if ct < 0:
                    ct = 0
                    num = i
        return num