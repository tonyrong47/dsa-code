class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        l = 0

        x = s.strip()

        for i in range(len(x)):
            if x[i] == " ":
                l = 0
            else:
                l += 1
        return l
