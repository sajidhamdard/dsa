The expression **`(n & (n - 1)) == 0`** is a commonly used bitwise trick to check if a number is a power of two. Let's break it down and analyze why it works.

---

### **Understanding the Bitwise Trick**

#### **1. Binary Representation of Powers of Two**

A number is a power of two if it has exactly **one bit set to `1`** in its binary representation.  
For example:

| Decimal | Binary  |
| ------- | ------- |
| 1       | `0001`  |
| 2       | `0010`  |
| 4       | `0100`  |
| 8       | `1000`  |
| 16      | `10000` |

All these numbers have **only one bit set**.

#### **2. What Happens with `n - 1`?**

If `n` is a power of two, subtracting `1` flips all bits **after the rightmost 1-bit**, turning it into `0`, and all bits to the right of it become `1`.  
For example:

| `n` (Power of 2) | `n` (Binary) | `n - 1` (Binary) |
| ---------------- | ------------ | ---------------- |
| 8                | `1000`       | `0111`           |
| 4                | `0100`       | `0011`           |
| 2                | `0010`       | `0001`           |
| 1                | `0001`       | `0000`           |

#### **3. What Does `n & (n - 1)` Do?**

The **bitwise AND (`&`)** operation keeps a `1` only if both corresponding bits are `1`.

- Since `n` has only one bit set to `1`, and `n - 1` has all bits flipped **after that `1`**, the result of `n & (n - 1)` is always `0`.

**Example for `n = 8`:**

```
   8   =  1000
   7   =  0111
   ------------
  8 & 7 = 0000  (== 0)
```

So, `(n & (n - 1)) == 0` is **true**, meaning `n` is a power of two.

---

### **Why Does This Fail for `-16`?**

1. **Negative numbers** are represented in **two's complement** form in binary.
2. In **two’s complement**, negative numbers have leading `1`s.
3. `-16` in binary (assuming 8-bit representation) is:
   ```
   -16  =  11110000  (in two's complement)
   -17  =  11101111
   -----------------
   -16 & -17 = 11100000 (≠ 0)
   ```
   Since `(-16 & -17) ≠ 0`, the condition fails.

### **Final Conclusion**

- **For positive powers of two** → `(n & (n - 1)) == 0` is `true`
- **For negative numbers** → This check is **not valid** because negative numbers are never powers of two.
- **For `n = -16`** → The check **fails**, returning `false`, which is correct.
