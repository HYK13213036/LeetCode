class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        key = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        value=["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
        res = ""
        for i in range(len(key)):
            for j in range(num//key[i]):
                res += value[i]
            num %= key[i]
        return res