class Solution:
    def minOperationsMaxProfit(self, customers: List[int], boardingCost: int, runningCost: int) -> int:
        if runningCost >= boardingCost*4:
            return -1
        currwaiting = 0
        p = 0
        maxp = 0
        maxindex = 0
        for i in range(len(customers)):
            currwaiting += customers[i]
            if currwaiting < 4:
                p += currwaiting * boardingCost - runningCost
                currwaiting = 0
            else:
                p += 4 * boardingCost - runningCost
                currwaiting -= 4
            if (maxp < p):
                maxp = p
                maxindex = i + 1
        if currwaiting > 0:
            if currwaiting < 4:
                p += currwaiting * boardingCost - runningCost
                currwaiting = 0
                if (maxp < p):
                    maxp = p
                    maxindex += 1
            else:
                p += (4 * boardingCost - runningCost) * currwaiting // 4
                if (maxp < p):
                    maxp = p
                    maxindex += currwaiting // 4
                currwaiting %= 4
                if currwaiting != 0:
                    p += currwaiting * boardingCost - runningCost
                    if (maxp < p):
                        maxp = p
                        maxindex += 1
        return maxindex

