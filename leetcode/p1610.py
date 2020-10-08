import math

class Solution:
    def visiblePoints(self, points: List[List[int]], angle: int, location: List[int]) -> int:
        pointangles = []
        pointontop = False
        for i in points:
            if location[0] == i[0] and location[1] == i[1]:
                pointontop = True
            else:
                pointangles.append(degrees(math.atan2(i[1]-location[1],i[0]-location[0]))+180)
        pointangles.sort()
        if 360 - pointangles[-1] < angle:
            pointangles += pointangles
            for i in range(len(pointangles)//2):
                pointangles[i + len(pointangles)//2] += 360
        start = 0
        maxsize = 0
        for i in range(len(pointangles)):
            if (pointangles[i] - angle > pointangles[start]):
                start += 1
            maxsize = max(maxsize, i+1-start)
        if pointontop:
            maxsize += 1
        return maxsize