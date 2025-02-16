### **Sign Bit and Negative Numbers in Binary (Two’s Complement)**

In Java (and most modern computing systems), **negative numbers are represented using "Two's Complement" notation**. Let’s break it down step by step.

---

## **1️⃣ What is the Sign Bit?**

- The **leftmost bit (MSB - Most Significant Bit)** in a binary number is called the **sign bit**.
- If the sign bit is **0**, the number is **positive**.
- If the sign bit is **1**, the number is **negative**.

For example, in an **8-bit system**:

| Decimal | Binary (8-bit) |
| ------- | -------------- |
| `5`     | `00000101`     |
| `-5`    | `11111011`     |

---

## **2️⃣ How Are Negative Numbers Stored? (Two's Complement)**

Negative numbers are stored in **Two’s Complement** form. To get the Two’s Complement of a number:

### **Steps to Get -N in Two's Complement:**

1. **Write the binary of `N` (positive number).**
2. **Invert all bits** (flip `0` to `1` and `1` to `0`).
3. **Add `1` to the result**.

### **Example: Representing `-5` in an 8-bit system**

1. **Binary of `5` (positive)**

   ```
   00000101
   ```

2. **Invert all bits (flip 0s and 1s)**

   ```
   11111010
   ```

3. **Add `1` to the result**
   ```
   11111011  (which is `-5` in two’s complement)
   ```

✅ **Final result: `11111011` (this represents `-5`)**

---

## **3️⃣ Why Use Two’s Complement Instead of Sign-Magnitude?**

Some might think, _"Why not just use the first bit as a sign and keep the rest as the magnitude?"_ (called **Sign-Magnitude Representation**).

The problem is that sign-magnitude has **two representations of zero** (`+0` and `-0`), which complicates calculations. Two’s Complement fixes this and allows **direct addition/subtraction** without extra logic.

---

## **4️⃣ Range of Integer Values in Java**

Since Java **int** is **32-bit**, its range is:

- **Minimum value:** `10000000 00000000 00000000 00000000` (`-2,147,483,648`)
- **Maximum value:** `01111111 11111111 11111111 11111111` (`2,147,483,647`)

📌 **Interesting Fact:** The range is **asymmetrical** because `-2^31` has no positive counterpart (`+2^31` would require another bit!).

---

## **5️⃣ Quick Checks for Sign and Negative Numbers**

### **Check if a number is negative using sign bit**

```java
int x = -5;
if ((x & (1 << 31)) != 0) {
    System.out.println("Negative number");
} else {
    System.out.println("Positive number");
}
```

✅ **Explanation**:

- `(1 << 31)` creates a mask `10000000 00000000 ...` (only the sign bit is `1`).
- **Bitwise AND** with `x`:
  - If the result is non-zero → The number is negative.
  - If the result is `0` → The number is positive.

---

### **Find Absolute Value Without `Math.abs()`**

```java
int absValue = (x < 0) ? (~x + 1) : x;
```

✅ **Explanation**:

- If `x` is negative, `~x + 1` gives its positive counterpart (Two’s Complement).
- If `x` is positive, return it as is.

---

## **Summary**

| Concept                       | Explanation                                           |
| ----------------------------- | ----------------------------------------------------- |
| **Sign Bit**                  | Leftmost bit (`1` for negative, `0` for positive)     |
| **Two’s Complement**          | Invert bits + Add `1` to get a negative number        |
| **Why Use Two’s Complement?** | Allows direct addition/subtraction, avoids `-0` issue |
| **Check Sign of a Number**    | `x & (1 << 31) != 0` checks if the number is negative |
| **Find Absolute Value**       | `(~x + 1)` converts negative to positive              |

Would you like an example of **adding/subtracting binary numbers using Two’s Complement**? 🚀

Great question! Let's break it down step by step. 🚀

### **Why does `1 ^ 1 = 0` in XOR?**

#### **1️⃣ Understanding XOR (`^`)**

The XOR (**exclusive OR**) operator follows these rules:

| A   | B   | A ^ B |
| --- | --- | ----- |
| 0   | 0   | 0     |
| 0   | 1   | 1     |
| 1   | 0   | 1     |
| 1   | 1   | 0     |

🔹 XOR returns **1** if the two bits are different.  
🔹 XOR returns **0** if the two bits are the same.

---

### **2️⃣ Why is `1 ^ 1 = 0`?**

- XOR checks if two bits are **different**.
- Since **1 and 1 are the same**, the result is `0`.

Think of it as a **toggle switch**:

- `0 ^ 0` → No change, still `0`
- `1 ^ 1` → No change, still `0`
- `1 ^ 0` → Different, so result is `1`
- `0 ^ 1` → Different, so result is `1`

---

### **3️⃣ Real-World Example: Swapping Two Numbers Without Temp Variable**

Did you know XOR can **swap two numbers without using extra space**? 🤯

```java
int a = 5, b = 3;
a = a ^ b;  // Step 1: a = 5 ^ 3 (stores XOR result)
b = a ^ b;  // Step 2: b = (5 ^ 3) ^ 3 = 5 (b gets the original value of a)
a = a ^ b;  // Step 3: a = (5 ^ 3) ^ 5 = 3 (a gets the original value of b)

System.out.println("a: " + a + ", b: " + b);
```

✅ Output:

```
a: 3, b: 5
```

Would you like more **XOR tricks** for coding problems? 🚀

### **Bitmasking Operations Explained Step by Step 🚀**

Let’s break down each expression **bit by bit** using `5` in binary.

---

## **Step 1: Convert `5` to Binary**

```
5 in binary →  0101
```

Each bit position represents a power of 2:

```
Bit positions:  3   2   1   0
               (8) (4) (2) (1)
5 (decimal) →  0   1   0   1  (binary)
```

Now, let’s evaluate each expression.

---

## **1️⃣ `5 & (1 << 0)` → Check if the 0th bit is set**

Expression:

```java
5 & (1 << 0)
```

### **Step 1: Compute `(1 << 0)`**

`1` in binary:

```
0001
```

Left shift by `0` means **no change**:

```
1 << 0 = 0001
```

### **Step 2: Apply Bitwise AND (`&`)**

```
   0101   (5)
&  0001   (1 << 0)
--------------
   0001   (1 in decimal)
```

✅ **Result: `1`**  
📌 **This checks if the 0th bit of `5` is set (1)**.

---

## **2️⃣ `5 | (1 << 1)` → Set the 1st bit**

Expression:

```java
5 | (1 << 1)
```

### **Step 1: Compute `(1 << 1)`**

```
1 (0001) shifted left by 1:
  0010
```

### **Step 2: Apply Bitwise OR (`|`)**

```
   0101   (5)
|  0010   (1 << 1)
--------------
   0111   (7 in decimal)
```

✅ **Result: `7`**  
📌 **This sets the 1st bit of `5` to `1` (ensuring that bit is turned on).**

---

## **3️⃣ `5 & ~(1 << 0)` → Clear the 0th bit**

Expression:

```java
5 & ~(1 << 0)
```

### **Step 1: Compute `(1 << 0)`**

```
1 << 0 = 0001
```

### **Step 2: Compute `~(1 << 0)` (Bitwise NOT)**

```
~0001 = 1110
```

(Note: Java uses 32-bit integers, but we focus only on the last 4 bits.)

### **Step 3: Apply Bitwise AND (`&`)**

```
   0101   (5)
&  1110   (~0001)
--------------
   0100   (4 in decimal)
```

✅ **Result: `4`**  
📌 **This clears (sets to 0) the 0th bit of `5`**.

---

## **4️⃣ `5 ^ (1 << 0)` → Toggle the 0th bit**

Expression:

```java
5 ^ (1 << 0)
```

### **Step 1: Compute `(1 << 0)`**

```
1 << 0 = 0001
```

### **Step 2: Apply XOR (`^`)**

```
   0101   (5)
^  0001   (1 << 0)
--------------
   0100   (4 in decimal)
```

✅ **Result: `4`**  
📌 **This toggles (flips) the 0th bit of `5`. If it was `1`, it becomes `0`.**

---

## **Final Summary**

| Expression      | Operation               | Result (Decimal) | Binary Result |
| --------------- | ----------------------- | ---------------- | ------------- | ------ |
| `5 & (1 << 0)`  | Check if 0th bit is `1` | `1`              | `0001`        |
| `5              | (1 << 1)`               | Set the 1st bit  | `7`           | `0111` |
| `5 & ~(1 << 0)` | Clear the 0th bit       | `4`              | `0100`        |
| `5 ^ (1 << 0)`  | Toggle the 0th bit      | `4`              | `0100`        |

---

### **Where is This Used?**

✔ **Checking if a bit is set (`&`)** – Used in permission systems  
✔ **Setting a bit (`|`)** – Used in enabling flags  
✔ **Clearing a bit (`& ~`)** – Used to turn off a setting  
✔ **Toggling a bit (`^`)** – Used in encryption, Gray codes

Would you like to see a real-world coding problem using this? 🚀

=============================================
(num & 1) == 0 checks if number is even
