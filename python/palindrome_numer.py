# Palindrome Number
# Given an integer x, return true if x is a palindrome, and false otherwise.

class Solution(object):
    def isPalindrome(self,x):
        x = str(x)
        return x == x[::-1]
    
# Example Usage

if __name__ == "__main__":
    s = Solution()
    print(s.isPalindrome(121))  # Prints True 
    print(s.isPalindrome(-121))  # Prints False
    print(s.isPalindrome(10))  # Prints False