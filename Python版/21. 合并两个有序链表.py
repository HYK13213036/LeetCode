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
        dummy = ListNode(0)  # 头哨兵
        cur = dummy
        while l1 and l2:
            if l1.val <= l2.val:
                cur.next = l1   # cur下个节点为val小的
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
            cur = cur.next      # 把cur指向其下个结点
        if l1 != None:
            cur.next = l1
        else:
            cur.next = l2
        return dummy.next