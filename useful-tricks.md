#### **`len(n)` Function**
```java
int len(int n) {
    return (int) Math.log10(n) + 1;
}
```
- **`Math.log10(n)`** gives the number of digits minus 1.
- **Adding `+1`** gives the actual count of digits.

| `n` | `Math.log10(n)` | `len(n)` (Digits) |
|----|--------------|----------------|
| 9  | 0.95        | 1              |
| 10 | 1.0         | 2              |
| 123 | 2.08       | 3              |
| 4567 | 3.66      | 4              |
| 10000 | 4.0      | 5              |

#### skipping numbers

`(int)Math.pow(10, len(n))` generates the smallest number with `len(n) + 1` digits (e.g., `99 → 100`, `999 → 1000`). It is useful for skipping ranges efficiently, especially when avoiding even-length numbers in prime or palindrome checks. This technique optimizes performance by reducing unnecessary iterations. 🚀

#### Identifying overflow

To check if a number **overflows** the `int` range in Java, remember:  

### **🔹 Integer Limits in Java**
- **`int` range**: **`-2,147,483,648` to `2,147,483,647`** (`Integer.MIN_VALUE` to `Integer.MAX_VALUE`)  
- Any number **greater than `2,147,483,647`** or **less than `-2,147,483,648`** **will overflow** `int`.

### **🔹 Checking Overflow for `2076180480`**
Since:
```
2076180480 > 2147483647 (Integer.MAX_VALUE)
```
✅ **This number overflows the `int` range**.

---

### **🔹 How to Detect Overflow in Java?**
#### **1️⃣ Use `long` Instead of `int`**
If a calculation might exceed `int`, use `long`:
```java
long num = 2076180480L; // Safe in long, but overflows int
```

#### **2️⃣ Check Before Casting**
```java
if (num > Integer.MAX_VALUE || num < Integer.MIN_VALUE) {
    System.out.println("Overflow detected!");
} else {
    int safeNum = (int) num; // Cast only if safe
}
```

#### **3️⃣ Catch Arithmetic Overflow (Using Math)**
For operations like multiplication:
```java
int a = 100000, b = 50000;
long res = (long) a * b; // Convert before multiplication
if (res > Integer.MAX_VALUE) {
    System.out.println("Overflow detected!");
} else {
    int result = (int) res; // Safe casting
}
```

✅ **Always check limits before casting or doing arithmetic to avoid unexpected integer overflow!** 🚀

#### **finding prime while skipping many numbers**
```java
boolean isPrime(int num) {
   if (num < 2) return false;
   if (num % 2 == 0 && num != 2) return false;
   for (int i = 3; i * i <= num; i += 2) {  
     if (num % i == 0) return false;  
   }
   return true;
}
```

#### **Why Is It Faster?**
1. **Reduces Iterations from O(n) → O(√n)**  
   - Instead of checking `num` divisibility up to `num-1`, we **only check up to `√num`**.
   - Example: If `num = 1000000`, instead of checking **999,998 numbers**, we only check **≈1000 numbers**.

2. **Skips Even Numbers**  
   - After checking `2`, we **only check odd numbers (`i += 2`)**.
   - This reduces the number of iterations by half!

#### **Time Complexity**
- **Optimized Approach:** **O(√n)**  
- **Example Comparison for `num = 10^9`**  
  - **Brute Force:** ~1,000,000,000 iterations ❌  
  - **Optimized:** ~31,622 iterations ✅ **(Much faster)**  


#### diagonal and anti-diagonal indices
---

### **1️⃣ Primary (Main) Diagonal**
- The **primary diagonal** consists of elements where **row index = column index** (`arr[i][i]`).
- It goes from **top-left to bottom-right**.

**Example (3×3 matrix)**:
```
1  2  3
4  5  6
7  8  9
```
🔹 **Primary Diagonal Elements** = `{1, 5, 9}` (indices: `[0][0]`, `[1][1]`, `[2][2]`)

💡 **Formula**:
```java
for (int i = 0; i < n; i++) {
    System.out.print(arr[i][i] + " ");
}
```

---

### **2️⃣ Secondary (Anti) Diagonal**
- The **secondary diagonal** consists of elements where **row index + column index = size - 1** (`arr[i][n-i-1]`).
- It goes from **top-right to bottom-left**.

**Same 3×3 matrix:**
```
1  2  3
4  5  6
7  8  9
```
🔹 **Secondary Diagonal Elements** = `{3, 5, 7}` (indices: `[0][2]`, `[1][1]`, `[2][0]`)

💡 **Formula**:
```java
for (int i = 0; i < n; i++) {
    System.out.print(arr[i][n-i-1] + " ");
}
```

---

### **🔹 Summary**
| Type              | Formula            | Example (3×3)  |
|------------------|-------------------|---------------|
| **Primary Diagonal**   | `arr[i][i]`      | `{1, 5, 9}`   |
| **Secondary Diagonal** | `arr[i][n-i-1]`  | `{3, 5, 7}`   |

📌 **Diagonals are useful in matrix operations, image processing, and mathematical computations!** 

### Java - map.merge(num, 1, Integer::sum);

You can use Map.merge() to update a count in a Map<K, Integer>. If the key is already present, it increases the count; otherwise, it sets it to 1.

### map.put(num, map.getOrDefault(num, 0) + 1); //similar to merge


### **Shortcut to Check if a Bit is Set or Not in a Binary Number**  

To check if the **k-th bit** (0-based index) of a number `n` is **set (1) or not set (0)**, use this bitwise trick:

```java
if ((n & (1 << k)) != 0) {
    System.out.println("Bit is SET (1)");
} else {
    System.out.println("Bit is NOT set (0)");
}
```

### **How It Works?**
1. `1 << k` → Left shifts `1` by `k` positions, creating a mask.  
2. `n & (1 << k)` → Checks if the `k-th` bit is `1`.  
   - If result **≠ 0**, the bit is **set (1)**.  
   - If result **= 0**, the bit is **not set (0)**.
  
### Unique list

`Set<List<Integer>>` works fine because Java's HashSet uses the `equals()` and `hashCode()` methods of List to check for duplicates.

```java
Set<List<Integer>> uniqueSubsets = new HashSet<>(); 
```

### List<Integer to int[]

```java
List<Integer> list = List.of(1, 2, 3, 4, 5);
int[] array = list.stream().mapToInt(Integer::intValue).toArray();
```

### Sort a 2d array

```java
int[][] scoreWithIndex = new int[n][2];
// Sort the array in descending order of score
Arrays.sort(scoreWithIndex, (a, b) -> b[0] - a[0]);
```

### Find max from the array
```java
Arrays.stream(score).max().getAsInt();
```

### Integer comparison to avoid overflow issues

```java
(a, b) -> Integer.compare(b.getValue(), a.getValue()); //It’s a safe and idiomatic way to compare integers.
```

### Reverse sorting

```java
Arrays.sort(arr, Collections.reverseOrder());
```


### Character class useful methods

Of course!  
The `Character` class in Java has many **handy static methods** that are very useful for **competitive programming**, especially when dealing with strings, parsing, and validation.

Here’s a **compact list of the most useful methods** you should know:

---

### **Most Useful `Character` Methods:**

| Method | Purpose | Example |
|:------|:--------|:--------|
| `Character.isLetter(ch)` | Checks if `ch` is a letter (a-z or A-Z) | `'a' → true`, `'9' → false` |
| `Character.isDigit(ch)` | Checks if `ch` is a digit (0-9) | `'5' → true`, `'b' → false` |
| `Character.isLetterOrDigit(ch)` | Checks if `ch` is a letter **or** digit | `'c' → true`, `'7' → true`, `'#' → false` |
| `Character.isLowerCase(ch)` | Checks if `ch` is a lowercase letter | `'g' → true`, `'G' → false` |
| `Character.isUpperCase(ch)` | Checks if `ch` is an uppercase letter | `'G' → true`, `'g' → false` |
| `Character.toLowerCase(ch)` | Converts a character to lowercase | `'A' → 'a'`, `'b' → 'b'` |
| `Character.toUpperCase(ch)` | Converts a character to uppercase | `'a' → 'A'`, `'B' → 'B'` |
| `Character.isWhitespace(ch)` | Checks if `ch` is a whitespace (space, tab, etc.) | `' ' → true`, `'a' → false` |
| `Character.getNumericValue(ch)` | Converts a char digit or letter to int | `'5' → 5`, `'A' → 10`, `'F' → 15` |
| `Character.compare(ch1, ch2)` | Compares two characters lexicographically | `'a', 'b' → negative (a < b)` |
| `Character.isAlphabetic(ch)` | Checks if `ch` is an alphabetic character (letter) | `'A' → true`, `'z' → true` |
