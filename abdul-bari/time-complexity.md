Order of common time complexities from smallest to largest:

\[
O(1) < O(\log n) < O(\sqrt{n}) < O(n) < O(n \log n) < O(n^2) < O(n^3) < \dots < O(2^n) < O(n!) < O(n^n)
\]

This represents the increasing order of growth rates, where smaller complexities are more efficient for large inputs.

### **1️⃣ O(n) - Linear Time Complexity**
**Example:** Printing numbers from `1` to `n`
```java
for (int i = 1; i <= n; i++) {
    System.out.println(i);
}
```
✅ **Iterations (n = 5):**  
1 → 2 → 3 → 4 → 5 → **(Total = n times)**  

---

### **2️⃣ O(n²) - Quadratic Time Complexity**
**Example:** Printing all pairs `(i, j)`
```java
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        System.out.println(i + "," + j);
    }
}
```
✅ **Iterations (n = 3):**  
(1,1) (1,2) (1,3)  
(2,1) (2,2) (2,3)  
(3,1) (3,2) (3,3)  
**(Total = n × n = n² times)**  

---

### **3️⃣ O(n³) - Cubic Time Complexity**
**Example:** Printing all triplets `(i, j, k)`
```java
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
            System.out.println(i + "," + j + "," + k);
        }
    }
}
```
✅ **Iterations (n = 2):**  
(1,1,1) (1,1,2)  
(1,2,1) (1,2,2)  
(2,1,1) (2,1,2)  
(2,2,1) (2,2,2)  
**(Total = n × n × n = n³ times)**  

---

### **4️⃣ O(log₂n) - Logarithmic Time Complexity**
**Example:** Binary Search (Reduces search space by half each time)
```java
int binarySearch(int[] arr, int target) {
    int left = 0, right = arr.length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```
✅ **Iterations (n = 16):**  
- Search in **[1-16]** → Pick **8**  
- Search in **[9-16]** → Pick **12**  
- Search in **[9-11]** → Pick **10**  
- Search in **[9-9]** → Done  

**(Total Iterations ≈ log₂n = log₂16 = 4 steps)**  

---

### **5️⃣ O(2ⁿ) - Exponential Time Complexity**
**Example:** Fibonacci using recursion
```java
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
```
✅ **Iterations (n = 4):**  
```
                fib(4)
              /       \
        fib(3)        fib(2)
       /     \        /     \
   fib(2)   fib(1)  fib(1)  fib(0)
  /     \
fib(1)  fib(0)
```
**(Total calls ≈ 2ⁿ = 2⁴ = 16 recursive calls)**  

---

### **6️⃣ O(n!) - Factorial Time Complexity**
**Example:** Generating all permutations of `n` elements
```java
void permute(List<Integer> arr, int l, int r) {
    if (l == r) System.out.println(arr);
    else {
        for (int i = l; i <= r; i++) {
            Collections.swap(arr, l, i);
            permute(arr, l + 1, r);
            Collections.swap(arr, l, i);
        }
    }
}
```
✅ **Iterations (n = 3):**  
- **n = 3 → 3! = 6 Permutations**  
  ```
  123, 132, 213, 231, 312, 321
  ```
- **n = 4 → 4! = 24 Permutations**  

---

### **📌 Summary Table**
| Complexity | Example | Iterations (n = 5) |
|------------|----------|------------------|
| **O(1)** | Return first element | `1` |
| **O(n)** | Loop from 1 to n | `5` |
| **O(n²)** | Nested loops | `25` |
| **O(n³)** | Triple nested loops | `125` |
| **O(log₂n)** | Binary Search | `log₂5 ≈ 3` |
| **O(2ⁿ)** | Fibonacci Recursion | `2⁵ = 32` |
| **O(n!)** | Permutations | `5! = 120` |

---

🚀 **Final Tip:**  
- **O(log n) or O(n)** is **fast** ✅  
- **O(n²) or O(n³)** is **slow** ❌  
- **O(2ⁿ) or O(n!)** is **very slow** ⛔ (Avoid for large `n`)

```java
int i  = 1;
int k = 1;
while(k < n) {
 System.out.println("Hello World");
 k = k +i;
 i++;
}
```

### **Step-by-step Execution**  
The variables `i` and `k` evolve as follows:

| Iteration | `i` Value | `k` Update (`k = k + i`) |
|-----------|----------|------------------|
| 1         | 1        | `k = 1 + 1 = 2`  |
| 2         | 2        | `k = 2 + 2 = 4`  |
| 3         | 3        | `k = 4 + 3 = 7`  |
| 4         | 4        | `k = 7 + 4 = 11` |
| 5         | 5        | `k = 11 + 5 = 16` |
| 6         | 6        | `k = 16 + 6 = 22` |
| 7         | 7        | `k = 22 + 7 = 29` |
| ...       | ...      | ...              |

Each iteration increments `i` and adds `i` to `k`.  
So, after `t` iterations, `k` becomes:  

\[
k = 1 + 2 + 3 + \dots + t
\]

This forms the sum of the first `t` natural numbers:

\[
k = \frac{t (t+1)}{2}
\]

---

### **Finding Time Complexity**  
The loop runs until `k ≥ n`. So, we solve for `t`:

\[
\frac{t (t+1)}{2} \geq n
\]

Approximating for large `t`:

\[
\frac{t^2}{2} \approx n
\]

\[
t^2 \approx 2n
\]

\[
t \approx \sqrt{2n}
\]

Thus, the loop runs **O(√n)** times.

---

### **Final Answer:**  
⏳ **Time Complexity:** **O(√n)**
