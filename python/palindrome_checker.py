def is_palindrome_string(s):
    """
    Check if a string is palindrome (ignoring case and spaces)
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    # Convert to lowercase and remove spaces
    s = s.lower().replace(' ', '')
    
    left = 0
    right = len(s) - 1
    
    while left < right:
        if s[left] != s[right]:
            return False
        left += 1
        right -= 1
    
    return True

def is_palindrome_number(num):
    """
    Check if a number is palindrome
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if num < 0:
        return False
    
    original = num
    reversed_num = 0
    
    while num > 0:
        reversed_num = reversed_num * 10 + num % 10
        num //= 10
    
    return original == reversed_num

def longest_palindrome_substring(s):
    """
    Find the longest palindromic substring
    Time Complexity: O(n²)
    Space Complexity: O(1)
    """
    if not s:
        return ""
    
    start = 0
    max_len = 1
    
    for i in range(len(s)):
        # Check for odd length palindromes
        left, right = i, i
        while left >= 0 and right < len(s) and s[left] == s[right]:
            current_len = right - left + 1
            if current_len > max_len:
                start = left
                max_len = current_len
            left -= 1
            right += 1
        
        # Check for even length palindromes
        left, right = i, i + 1
        while left >= 0 and right < len(s) and s[left] == s[right]:
            current_len = right - left + 1
            if current_len > max_len:
                start = left
                max_len = current_len
            left -= 1
            right += 1
    
    return s[start:start + max_len]

# Test the functions
if __name__ == "__main__":
    # Test string palindrome
    test_strings = ["racecar", "A man a plan a canal Panama", "hello", "Madam"]
    print("String Palindrome Tests:")
    for string in test_strings:
        result = is_palindrome_string(string)
        print(f"'{string}' is palindrome: {result}")
    
    print("\nNumber Palindrome Tests:")
    test_numbers = [121, 12321, 123, -121, 0]
    for num in test_numbers:
        result = is_palindrome_number(num)
        print(f"{num} is palindrome: {result}")
    
    print("\nLongest Palindrome Substring Tests:")
    test_strings = ["babad", "cbbd", "racecar", "abcdef"]
    for string in test_strings:
        result = longest_palindrome_substring(string)
        print(f"Longest palindrome in '{string}': '{result}'")