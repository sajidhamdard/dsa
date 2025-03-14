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
