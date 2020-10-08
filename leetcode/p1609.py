# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:    
    def isEvenOddTree(self, root: TreeNode) -> bool:
        if root.val % 2 == 0:
            return False
        lis = []
        lis.append(root)
        amt = 0
        ct = 0
        while amt != len(lis):
            ct+=1
            prevamt = amt
            amt = len(lis)
            for i in range(prevamt, amt):
                if lis[i].left != None:
                    lis.append(lis[i].left)
                if lis[i].right != None:
                    lis.append(lis[i].right)
            if ct % 2 == 0:
                for i in range(amt, len(lis)):
                    if lis[i].val % 2 == 0:
                        return False
                    if i != amt and lis[i].val <= lis[i-1].val:
                        return False
            else:
                for i in range(amt, len(lis)):
                    if lis[i].val % 2 == 1:
                        return False
                    if i != amt and lis[i].val >= lis[i-1].val:
                        return False
        return True