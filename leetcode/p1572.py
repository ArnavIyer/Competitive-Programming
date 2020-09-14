class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        sume=0
        for i in range(len(mat)):
            sume += mat[i][i]
            if (i != len(mat) -i-1):
                sume += mat[i][len(mat)-i-1]
        return sume