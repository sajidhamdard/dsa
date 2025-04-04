---

## 🪣 What is **Bucket Sort**?

**Bucket Sort** is a sorting algorithm that:
- Divides elements into multiple **buckets**
- Sorts each bucket individually (often using another sorting algorithm like quicksort or just placing directly)
- Then combines all buckets into the final sorted array

---

### ✅ Use case:
It's especially **efficient when input is uniformly distributed**, like floating-point numbers between `0.0` and `1.0`.

---

### 🧠 How it works (conceptually):

Let’s say we want to sort this array:

```
[0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51]
```

### 1. Create N buckets (like 0.0–0.1, 0.1–0.2, … 0.9–1.0)
```text
bucket[0] = []
bucket[1] = []
...
bucket[9] = []
```

### 2. Place each number into a bucket based on its value
```
0.42 → bucket[4]
0.32 → bucket[3]
0.23 → bucket[2]
...
```

### 3. Sort each bucket individually

### 4. Concatenate all buckets in order

---

### 💡 Java Example: Bucket sort for float values between 0 and 1

```java
void bucketSort(float[] arr) {
    int n = arr.length;
    List<Float>[] buckets = new List[n];

    // Create empty buckets
    for (int i = 0; i < n; i++) {
        buckets[i] = new ArrayList<>();
    }

    // Add elements to respective buckets
    for (float num : arr) {
        int bucketIndex = (int)(num * n); // index based on range
        buckets[bucketIndex].add(num);
    }

    // Sort individual buckets
    for (List<Float> bucket : buckets) {
        Collections.sort(bucket);
    }

    // Concatenate all buckets into original array
    int index = 0;
    for (List<Float> bucket : buckets) {
        for (float num : bucket) {
            arr[index++] = num;
        }
    }
}
```

---

### 🔥 In practice:
- It's **not used** for general-purpose sorting (like merge sort or quicksort), but
- It's **very useful** when:
  - You have bounded values (like digits, characters, etc.)
  - Or you can distribute elements into known ranges

---

### Bonus: Bucket sort is often used in **frequency-based problems** (like `frequencySort`), where each bucket is a list of characters with a given frequency.

Awesome! Here's how you can solve the `frequencySort` problem using **bucket sort** instead of a max heap.

---

### 🧠 Idea:
- Count frequency of each character.
- Create an array of buckets where index = frequency.
- Place characters into their corresponding frequency bucket.
- Traverse buckets from high to low and build the result string.

---

### ✅ Code (Bucket Sort version):

```java
class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> freqMap = new HashMap<>();

        // 1. Count frequency
        for (char c : s.toCharArray()) {
            freqMap.merge(c, 1, Integer::sum);
        }

        // 2. Create buckets where index = frequency
        // Max frequency cannot be more than length of the string
        List<Character>[] buckets = new List[s.length() + 1];
        for (int i = 0; i < buckets.length; i++) {
            buckets[i] = new ArrayList<>();
        }

        // 3. Fill the buckets
        for (Map.Entry<Character, Integer> entry : freqMap.entrySet()) {
            buckets[entry.getValue()].add(entry.getKey());
        }

        // 4. Build the result string from buckets (high freq to low)
        StringBuilder sb = new StringBuilder();
        for (int freq = buckets.length - 1; freq > 0; freq--) {
            for (char c : buckets[freq]) {
                sb.append(String.valueOf(c).repeat(freq));
            }
        }

        return sb.toString();
    }
}
```

---

### 🔍 Benefits of Bucket Sort here:
- No need for a PriorityQueue
- Linear time complexity in best-case: **O(n)** if frequencies are well-distributed
- Very clean and efficient for this type of problem

---

 Here's a **side-by-side comparison** of the two approaches used in `frequencySort` — **Heap-based** vs **Bucket Sort**:

---

### 📊 Time and Space Complexity

| Approach        | Time Complexity                            | Space Complexity         | Notes |
|----------------|---------------------------------------------|--------------------------|-------|
| **Max Heap**    | **O(n log k)** <br>(n = input size, k = distinct chars) | O(n + k)                 | PriorityQueue takes log time per insertion |
| **Bucket Sort** | **O(n)**                                   | O(n + k)                 | Fastest when max frequency is small |

---

### 🔍 Detailed Breakdown

#### ✅ **Max Heap**
- **Counting Frequencies:** O(n)
- **Heap Insertion:** O(k log k) where k = number of unique characters
- **Building result:** O(n)
- **Total:** `O(n + k log k)`  
  - Worst case `k = n` → `O(n log n)`

#### ✅ **Bucket Sort**
- **Counting Frequencies:** O(n)
- **Bucket creation & fill:** O(k)
- **Building result (traversing buckets):** O(n)
- **Total:** `O(n + k)`  
  - Worst case `k = n`, still `O(n)`

---

### 💡 Space Usage
- Both use:
  - `HashMap` for frequency count: O(k)
  - Result `StringBuilder`: O(n)
- Heap uses a `PriorityQueue`: O(k)
- Bucket sort uses `List[]` of size `n+1`: O(n)

---

### ✅ Summary

| Metric            | Max Heap     | Bucket Sort   |
|-------------------|--------------|---------------|
| Simpler to write  | ✅            | ✅            |
| Faster (in theory)| ❌ O(n log k) | ✅ O(n)       |
| Real-world usage  | ✅            | ✅            |
| Java 8 friendly   | ✅            | ✅            |

---

### 🧠 When to prefer Bucket Sort?
- When values can be grouped by a small bounded integer (like frequency).
- When performance matters and overhead of a heap is avoidable.

---

---

## 🤔 If we can solve it without a heap, why use a heap at all?

You're right — **both heap and bucket sort** solve the problem, so here's a breakdown of **when and why** to prefer one over the other.

---

## ✅ Heap is useful when:

1. **You care about custom sorting logic**  
   - Heap is flexible — you can sort by **frequency**, **lexical order**, or even combine criteria.
   - For example: "Sort by frequency desc, but if same freq, use alphabetical order" — easy with a heap comparator.

2. **The range of values (frequencies) is unknown or unbounded**
   - In bucket sort, you need to allocate an array of size = max frequency. If max frequency is 1 million, that’s inefficient.

3. **You only need top K frequent elements**  
   - Heap shines in problems like **Top K Frequent Elements**, because it gives you the top items without full sorting.

---

## ✅ Bucket sort is better when:

1. **You know frequencies are bounded and small**  
   - Like in your problem: max frequency ≤ string length

2. **You want linear time**  
   - No need to insert into a `PriorityQueue` which takes `O(log k)` per insertion.

3. **You don’t need any fancy custom sorting inside buckets**  
   - If frequency is the only criteria, just group and output.

---

## ⚖️ Which one to prefer here?

In **this specific problem** (`frequencySort`):
- **Bucket sort is more efficient**, because:
  - You already know the max frequency ≤ `s.length()`
  - No extra sorting logic is needed beyond frequency
- **Heap is more flexible**, but overkill here

---

## 🧠 Final takeaway:

> ✔️ **Use heap when you need dynamic, top-k, or complex sorting logic.**  
> ✔️ **Use bucket sort when frequency is small, bounded, and simple.**

---
