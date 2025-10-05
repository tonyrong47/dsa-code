#Palindrome Check

def is_palindrome(s):
    return s == s[::-1]

# Example usage
word = "racecar"
print(word, "is palindrome?", is_palindrome(word))  # Output: True
