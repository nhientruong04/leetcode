class Solution:
    def invertTree(self, root):
        if root == None or (root.left==None and root.right==None):
            return root
        nodes = [root]


        while len(nodes) > 0:
            curr_node = nodes.pop(0)

            # add children to queue
            if curr_node.left != None:
                nodes.append(curr_node.left)
            
            if curr_node.right != None:
                nodes.append(curr_node.right)

            temp_left_child = curr_node.left
            curr_node.left = curr_node.right
            curr_node.right = temp_left_child

        return root