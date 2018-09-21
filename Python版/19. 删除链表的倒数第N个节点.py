# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        first, end = dummy, dummy
        while n != 0:
            end = end.next
            n -= 1
        while end.next != None:
            first = first.next
            end = end.next
        first.next = first.next.next
        return dummy.next