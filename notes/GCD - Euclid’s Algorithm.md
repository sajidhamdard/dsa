## **📌 Euclid’s Algorithm**

🔹 **Euclid's Algorithm** is an efficient method for computing the **Greatest Common Divisor (GCD)** of two numbers.  
🔹 It is based on the principle that:  
 **GCD(a, b) = GCD(b, a % b)**  
 (i.e., the GCD of two numbers remains the same if the larger number is replaced by its remainder when divided by the smaller number).

---

## **🔹 Steps of Euclid’s Algorithm**

1️⃣ If `b == 0`, then `GCD(a, b) = a`.  
2️⃣ Otherwise, replace `a` with `b`, and `b` with `a % b`.  
3️⃣ Repeat until `b` becomes `0`.

---

## **🔹 Example**

Find **GCD(48, 18)** using Euclid's Algorithm:

| Step | a   | b   | a % b        |
| ---- | --- | --- | ------------ |
| 1    | 48  | 18  | 48 % 18 = 12 |
| 2    | 18  | 12  | 18 % 12 = 6  |
| 3    | 12  | 6   | 12 % 6 = 0   |

✅ **GCD = 6** (when `b` becomes `0`).

---

## **🔹 Java Implementation**

```java
public class EuclidsAlgorithm {
    public static int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    public static void main(String[] args) {
        int a = 48, b = 18;
        System.out.println("GCD of " + a + " and " + b + " is: " + gcd(a, b));
    }
}
```

**🔹 Output:**

```
GCD of 48 and 18 is: 6
```

---

## **🔹 Complexity Analysis**

- **Time Complexity:** **O(log(min(a, b)))** (Very fast!)
- **Space Complexity:** **O(1)** (Iterative) or **O(log n)** (Recursive)

---

## **🔹 Where is Euclid’s Algorithm Used?**

✅ **Cryptography** (RSA Algorithm for encryption).  
✅ **Computational Geometry** (Simplifying fractions, finding coprime numbers).  
✅ **Algorithms like LCM (Least Common Multiple)** (since LCM(a, b) = (a \* b) / GCD(a, b)).
