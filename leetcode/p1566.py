class Solution:
    def containsPattern(self, arr: List[int], m: int, k: int) -> bool:
        substorer = [[] for i in range(m)]
#       map for each thing in substorer
        for i in range(len(arr)-m+1):
            substorer[i%m].append(arr[i:i+m])
            
        for sublist in substorer:
            count = 1
            for i in range(len(sublist)-1):
                if sublist[i] == sublist[i+1]:
                    count+=1
                else:
                    count = 1
                if count >= k:
                    return True
        return False
            