In Java, you can add binary numbers in multiple ways. Here are the best approaches:

---

## **🔹 Method 1: Using `Integer.parseInt()` (Easy & Built-in)**

This method converts binary strings to decimal, adds them, and converts the result back to binary.

```java
public class BinaryAddition {
    public static void main(String[] args) {
        String a = "110"; // Binary of 6
        String b = "101"; // Binary of 5

        String result = addBinary(a, b);
        System.out.println("Sum: " + result); // Output: 1011 (Binary of 11)
    }

    public static String addBinary(String a, String b) {
        int num1 = Integer.parseInt(a, 2); // Convert binary to decimal
        int num2 = Integer.parseInt(b, 2);
        int sum = num1 + num2; // Add decimal numbers

        return Integer.toBinaryString(sum); // Convert back to binary
    }
}
```

✅ **Output:**

```
Sum: 1011
```

---

## **🔹 Method 2: Manual Binary Addition (Bitwise & Carry)**

This method **adds binary numbers manually** like how we do it on paper.

```java
public class ManualBinaryAddition {
    public static void main(String[] args) {
        String a = "110"; // Binary of 6
        String b = "101"; // Binary of 5

        String result = addBinary(a, b);
        System.out.println("Sum: " + result); // Output: 1011 (Binary of 11)
    }

    public static String addBinary(String a, String b) {
        StringBuilder result = new StringBuilder();
        int i = a.length() - 1, j = b.length() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += a.charAt(i--) - '0'; // Convert char to int (0 or 1)
            if (j >= 0) sum += b.charAt(j--) - '0';

            result.append(sum % 2); // Append 0 or 1
            carry = sum / 2; // Carry will be 1 if sum is 2 or 3
        }

        return result.reverse().toString();
    }
}
```

✅ **Output:**

```
Sum: 1011
```

---

## **🔹 Method 3: Using BigInteger for Large Numbers**

If you're dealing with **very large binary numbers**, `BigInteger` is the best choice.

```java
import java.math.BigInteger;

public class BigIntegerBinaryAddition {
    public static void main(String[] args) {
        String a = "110110101101101011"; // Large binary number
        String b = "101011011010110110";

        String result = addBinary(a, b);
        System.out.println("Sum: " + result);
    }

    public static String addBinary(String a, String b) {
        BigInteger num1 = new BigInteger(a, 2); // Convert binary to BigInteger
        BigInteger num2 = new BigInteger(b, 2);
        BigInteger sum = num1.add(num2); // Perform addition

        return sum.toString(2); // Convert back to binary
    }
}
```

✅ **Handles large binary numbers efficiently.**

---

## **🔹 Summary: Which Method to Use?**

| **Method**                      | **Best For**                       | **Performance** |
| ------------------------------- | ---------------------------------- | --------------- |
| `Integer.parseInt()`            | Small binary numbers               | O(1)            |
| **Manual Carry-based Addition** | Learning how binary addition works | O(n)            |
| **BigInteger**                  | Very large binary numbers          | O(n)            |

🚀 **Use `Integer.parseInt()` for simple cases. Use `BigInteger` for large numbers.**
