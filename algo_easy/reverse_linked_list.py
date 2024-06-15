class Solution:
    def reverseList(self, head):
        if head == None:
            return

        list_stack = [None]
        curr_node = head
        while curr_node!=None:
            list_stack.append(curr_node)
            curr_node = curr_node.next

        i = len(list_stack) - 1
        ret = list_stack[i]
        while i>0:
            list_stack[i].next = list_stack[i-1]
            i-=1

        return ret