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
