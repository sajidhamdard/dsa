### Ugly number ii

I solve this problem using the PriorityQueue and below is the solution for the same.

```java
class Solution {
    public int nthUglyNumber(int n) {
        PriorityQueue<Long> minHeap = new PriorityQueue<>();
        Set<Long> seen = new HashSet<>();
        int[] primes = new int[]{2,3,5};

        minHeap.offer(1l);
        long ugly = 1;

        for(int i = 1; i <= n; i++) {
            ugly = minHeap.poll();
            for(int prime : primes) {
                Long num  = prime * ugly;
                if(!seen.contains(num)) {
                    seen.add(num);
                    minHeap.offer(num);
                }
            }
        }
        return (int)ugly;
    }
}
```

But this solution was only beating 70% other java solutions. Better approach would be using DP which beats 100% other submissions

```
class Solution {
    public int nthUglyNumber(int n) {
        int[] primes = {2, 3, 5};
        int[] indices = {0, 0, 0};
        List<Integer> uglyArr = new ArrayList<>();
        uglyArr.add(1);
        for (int i = 1; i < n; ++i) {
            int[] nextUglies = {
                uglyArr.get(indices[0]) * primes[0],
                uglyArr.get(indices[1]) * primes[1],
                uglyArr.get(indices[2]) * primes[2]
            };
            int minValue = Math.min(nextUglies[0], Math.min(nextUglies[1], nextUglies[2]));
            uglyArr.add(minValue); 
            for (int j = 0; j < 3; ++j) {
                if (nextUglies[j] == minValue) {
                    indices[j]++;
                }
            }
        }
        return uglyArr.get(n - 1);
    }
}
```


Let's go step by step with an example for **n = 10** using the **Dynamic Programming (Three Pointers)** approach.

---

### **Step 1: Initialization**
- **Primes:** `{2, 3, 5}`
- **Pointers (indices):** `{0, 0, 0}` (tracks the position in `uglyArr` for multiples of 2, 3, and 5)
- **Ugly Number List (`uglyArr`):** `{1}` (we start with `1`)

---

### **Step 2: Generate Ugly Numbers**
For each step, we calculate three potential next ugly numbers by multiplying the current pointer values from `uglyArr` with 2, 3, and 5, then select the minimum.

| Step | Ugly Numbers (uglyArr) | Candidates (2×, 3×, 5×) | Min Ugly Number | Updated Indices |
|------|-------------------------|-----------------|-----------------|----------------|
| 1    | **{1}**                 | `{2, 3, 5}`     | `2`             | `{1, 0, 0}`    |
| 2    | **{1, 2}**              | `{4, 3, 5}`     | `3`             | `{1, 1, 0}`    |
| 3    | **{1, 2, 3}**           | `{4, 6, 5}`     | `4`             | `{2, 1, 0}`    |
| 4    | **{1, 2, 3, 4}**        | `{6, 6, 5}`     | `5`             | `{2, 1, 1}`    |
| 5    | **{1, 2, 3, 4, 5}**     | `{6, 6, 10}`    | `6`             | `{3, 2, 1}`    |
| 6    | **{1, 2, 3, 4, 5, 6}**  | `{8, 9, 10}`    | `8`             | `{4, 2, 1}`    |
| 7    | **{1, 2, 3, 4, 5, 6, 8}** | `{10, 9, 10}`  | `9`             | `{4, 3, 1}`    |
| 8    | **{1, 2, 3, 4, 5, 6, 8, 9}** | `{10, 12, 10}` | `10` | `{5, 3, 2}` |
| 9    | **{1, 2, 3, 4, 5, 6, 8, 9, 10}** | `{12, 12, 15}` | `12` | `{6, 4, 2}` |
| 10   | **{1, 2, 3, 4, 5, 6, 8, 9, 10, 12}** | `{16, 15, 15}` | `15` | `{6, 5, 3}` |

### **Final Output:**
The **10th ugly number** is **12**.

---

### **How It Works Efficiently**
1. Instead of checking every number (which is inefficient), we **only generate** numbers in sorted order.
2. The **three pointers (`indices[0]`, `indices[1]`, `indices[2]`)** track the next multiples of `2, 3, 5` efficiently.
3. We **always select the smallest** among the candidates to maintain order.
4. **Duplicate numbers are handled naturally** by incrementing all relevant pointers when multiple primes generate the same ugly number.

### **Key Observations**
- At each step, **only one or more of the three indices move forward**, ensuring numbers are generated in order.
- **No duplicates in `uglyArr`**, as the same number isn't inserted twice.

---

### **Comparison with Heap Approach**
| Approach | Time Complexity | Space Complexity | Explanation |
|----------|---------------|------------------|-------------|
| **Heap (PriorityQueue) + HashSet** | O(n log n) | O(n) | Each insertion/removal in heap takes log(n) time. |
| **DP + Three Pointers** | **O(n)** | O(n) | Only one pass through `n` numbers, constant time updates. |

🚀 **Conclusion:** This **DP + Three Pointers** approach is the optimal way to solve the **Nth Ugly Number** problem in **O(n)** time.
