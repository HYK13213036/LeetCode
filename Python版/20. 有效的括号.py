class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []  #使用list来代替栈
        for i in s:
            if i == '(':
                stack.append(')')
            elif i == '{':
                stack.append('}')
            elif i == '[':
                stack.append(']')
            elif len(stack) == 0:
                return False
            elif stack[-1] != i:
                return False
            else:
                stack.pop()
        return len(stack) == 0