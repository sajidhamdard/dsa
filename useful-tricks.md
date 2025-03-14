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
