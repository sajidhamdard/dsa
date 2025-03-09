### 1️⃣ Remove any characters other than `a-z` or `0-9`
```regex
[^a-z0-9]
```
- **Replacement**: `""` (empty string)
- **Example**:  
  - `"Hello@123!"` → `"hello123"`  
  - `"A_B C"` → `"abc"`  

### 2️⃣ Convert a string into words (split by non-alphabetic characters)
```regex
[^a-zA-Z]+
```
- **Use**: `split()` method
- **Example**:  
  - `"Hello,World!123"` → `["Hello", "World"]`

### 3️⃣ Remove spaces (trim and remove all spaces)
```regex
\s+
```
- **Replacement**: `""`
- **Example**:  
  - `"  Hello  World "` → `"HelloWorld"`

### 4️⃣ Remove leading and trailing spaces
```regex
^\s+|\s+$
```
- **Replacement**: `""`
- **Example**:  
  - `"  Hello World  "` → `"Hello World"`

### 5️⃣ Extract all numbers from a string
```regex
\d+
```
- **Use**: `findall()`
- **Example**:  
  - `"abc 123 def 456"` → `["123", "456"]`

### 6️⃣ Extract all words (only a-z, A-Z)
```regex
[a-zA-Z]+
```
- **Use**: `findall()`
- **Example**:  
  - `"Hello123 World!"` → `["Hello", "World"]`

### 7️⃣ Check if a string is a valid integer
```regex
^-?\d+$
```
- **Example**:
  - `"123"` ✅  
  - `"-456"` ✅  
  - `"12.34"` ❌  

### 8️⃣ Check if a string is a valid floating-point number
```regex
^-?\d+(\.\d+)?$
```
- **Example**:
  - `"123"` ✅  
  - `"3.14"` ✅  
  - `"abc"` ❌  

### 9️⃣ Match a valid variable name (C++, Java, Python)
```regex
^[a-zA-Z_][a-zA-Z0-9_]*$
```
- **Example**:
  - `"valid_variable"` ✅  
  - `"1invalid"` ❌  

### 🔟 Find duplicate words in a sentence
```regex
\b(\w+)\s+\1\b
```
- **Example**:

A commonly used **regex for validating emails** is:  

```regex
^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$
```

### 📌 Explanation:
- `^` → Start of string
- `[a-zA-Z0-9._%+-]+` → Local part (before `@`)
  - Can contain letters, digits, dots (`.`), underscores (`_`), percent (`%`), plus (`+`), and hyphen (`-`).
- `@` → Must have an `@` symbol
- `[a-zA-Z0-9.-]+` → Domain name
  - Can contain letters, digits, dots (`.`), and hyphens (`-`).
- `\.` → Must have a dot (`.`) before the domain extension
- `[a-zA-Z]{2,}` → Top-level domain (TLD) must have at least **2** letters (e.g., `.com`, `.org`, `.io`)
- `$` → End of string

### ✅ Valid Emails:
- `test@example.com`
- `user.name+tag@domain.co.in`
- `abc123@xyz.org`

### ❌ Invalid Emails:
- `@example.com` ❌ (Missing local part)
- `user@.com` ❌ (Invalid domain)
- `user@domain,com` ❌ (Comma instead of `.`)

💡 **Note**: While this regex covers most cases, **RFC 5322** allows even more complex emails, which are harder to validate using regex alone.

  - `"This is is a test"` → Matches `"is is"`
