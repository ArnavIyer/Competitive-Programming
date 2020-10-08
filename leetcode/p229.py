class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        num1 = math.inf
        num2 = math.inf
        c1 = 0
        c2 = 0
        ans = []
        for i in nums:
            if num1 == i:
                c1 += 1
            elif num2 == i:
                c2 += 1
            else:
                if c1 == 0:
                    num1 = i
                    c1 = 1
                elif c2 == 0:
                    num2 = i
                    c2 = 1
                else:
                    c1 -= 1
                    c2 -= 1
        thresh = len(nums)//3
        c1 = 0
        c2 = 0
        for i in nums:
            if i == num1:
                c1 += 1
            if i == num2:
                c2 += 1
        if c1 > thresh:
            ans.append(num1)
        if c2 > thresh:
            ans.append(num2)
        return ans