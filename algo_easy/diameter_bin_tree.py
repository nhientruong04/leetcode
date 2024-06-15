class Solution:
    def __init__(self) -> None:
        self.diameter_stack = []

    def maxDepth(self, root):
        if root == None:
            return 0
        
        left_length = 1 + self.maxDepth(root.left)
        right_length = 1 + self.maxDepth(root.right)

        diameter = left_length+right_length-2

        if len(self.diameter_stack)==0:
            self.diameter_stack.append(diameter)
        elif diameter > self.diameter_stack[-1]:
            self.diameter_stack.append(diameter)

        return max(left_length, right_length)

    def diameterOfBinaryTree(self, root):
        if root == None or (root.left==None and root.right==None):
            return 0
        
        self.maxDepth(root)

        return self.diameter_stack[-1]