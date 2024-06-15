class Solution:
    def maxDepth(self, root):
        if root == None:
            return 0

        left_length = 1 + self.maxDepth(root.left)
        right_length = 1 + self.maxDepth(root.right)

        if left_length<0 or right_length<0 or abs(left_length-right_length) > 1:
            return -2

        return max(left_length, right_length)

    def isBalanced(self, root):
        if root == None or (root.left==None and root.right==None):
            return True
        
        return False if self.maxDepth(root)<0 else True