The **Sieve of Eratosthenes** is an efficient algorithm for finding all prime numbers up to a given limit, typically used in **DSA (Data Structures and Algorithms)** for **fast prime number generation**.  

### **How It Works:**
1. Create a boolean array `isPrime[]` of size **N+1**, initialized to `true`.
2. Mark `isPrime[0]` and `isPrime[1]` as `false` since 0 and 1 are not prime.
3. Iterate from `2` to `√N`, marking all multiples of each prime as `false`.
4. The remaining `true` indices represent prime numbers.

### **Time Complexity:**
- **O(N log log N)** (much faster than checking primes individually).

### **Use Cases:**
- Finding all primes in a range efficiently.
- Optimizing prime factorization problems.
- Used in **competitive programming** for **fast prime lookups**.

Here’s a **Java implementation** of the **Sieve of Eratosthenes** to find all prime numbers up to `N`:  

### **Code:**
```java
import java.util.*;

public class SieveOfEratosthenes {
    public static void sieve(int n) {
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true); // Assume all numbers are prime
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) { // If i is prime
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false; // Mark all multiples of i as non-prime
                }
            }
        }

        // Print all prime numbers
        System.out.println("Prime numbers up to " + n + ":");
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                System.out.print(i + " ");
            }
        }
    }

    public static void main(String[] args) {
        int N = 100; // Change this to any number
        sieve(N);
    }
}
```

### **Explanation:**
1. **`isPrime[]` array**: Used to mark prime numbers.
2. **Eliminate multiples**: Starting from `2`, mark multiples as `false`.
3. **Efficiency**: Instead of checking each number individually, we skip marked non-primes, making it **O(N log log N)**.

### **Example Output (for N = 100):**
```
Prime numbers up to 100:
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
```
