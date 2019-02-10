# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        Head = ListNode(0)
        p = Head
        while l1 != None or l2 != None:
            if l2 == None or (l1 != None and l1.val < l2.val):
                p.val = l1.val
                l1 = l1.next
            else:
                p.val = l2.val
                l2 = l2.next
            if l1 != None or l2 != None:    
                p.next = ListNode(0)
                p = p.next
        return Head
