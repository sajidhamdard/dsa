## [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)

### ✅ Solution (Beats 99%)

```java
class Solution {
    public boolean isPalindrome(String s) {
        int l = 0;
        int r = s.length() - 1;
        while(l < r) {
            if(!isAlphaNumeric(s.charAt(l))) {
                l++;
            } else if(!isAlphaNumeric(s.charAt(r))) {
                r--;
            } else {
                if(!bothEqual(s.charAt(l), s.charAt(r))) {
                    return false;
                }
                l++;
                r--;
            }
        }
        return true;
    }
    private boolean isAlphaNumeric(char c) {
        return (c >= 'a' && c <= 'z')
            || (c >= '0' && c <= '9')
            || (c >= 'A' && c <= 'Z');
    }

    private boolean bothEqual(char a, char b) {
        //handling edge case for numbers
        if((a >= '0' && a <= '9') || (b >= '0' && b <= '9')) {
            return a == b;
        }
        return (a == b || a - 'a' + 'A' == b || a - 'A' + 'a' == b);
    }
}

````

### 📊 Time Complexity:

`O(n)` : where n is the length of the string.

### 🧠 Space Complexity:

`O(1)` — No extra space used

### ❌ Mistakes / Challenges Faced:


*We could have easily solved this problem using Java library methods or built-in `String` functions, but that wouldn't serve the core purpose of the problem. Instead, we used the two-pointer approach, which is a more efficient and precise technique that checks for a valid palindrome character by character. To further enhance our understanding, we avoided using library methods like `Character.isLetterOrDigit()` or `toLowerCase()` and instead relied on ASCII-based logic to manually handle alphanumeric checks and case-insensitive comparisons.*

### 🧩 Pattern/Topic:

`String`, `Two Pointers`
