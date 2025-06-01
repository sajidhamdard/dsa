## 🔹 1. **What is "in-cache" access in arrays?**

Modern CPUs use a **cache**—a small, super-fast memory close to the CPU—to speed up data access.

* When your program accesses an element in memory (like in an array), **the CPU tries to load not just that element, but nearby data into the cache**. This is called a **cache line** (typically 64 bytes).
* So, if your next access is nearby, it's **already in cache**, and you get a big performance boost.

**In-cache** access means the data is already in the cache, so it's fast to read.

---

## 🔹 2. **What is Locality of Reference?**

This is a concept from computer architecture that explains **why certain memory access patterns are faster**.

There are two types:

### ✅ a. **Temporal Locality**

* If you access the **same data again and again**, it stays in the cache.
* Example:

  ```java
  int x = arr[5];
  int y = arr[5];  // Fast! Already in cache.
  ```

### ✅ b. **Spatial Locality**

* If you access data that is **close to recently accessed data**, it's likely in the same cache line.
* Example:

  ```java
  for (int i = 0; i < n; i++) {
      sum += arr[i];  // Fast access, as arr[i] is next to arr[i-1]
  }
  ```

---

## 🔹 3. **Why is this important in arrays?**

Arrays are stored in **contiguous memory**. This layout **benefits from spatial locality**.

**Good example (cache-friendly):**

```java
for (int i = 0; i < arr.length; i++) {
    process(arr[i]);
}
```

**Bad example (poor cache use):**

```java
for (int i = 0; i < arr.length; i += 16) {
    process(arr[i]);
}
```

Here, you're skipping many elements, so the CPU may need to load a new cache line every time — slow.

---

## 🔹 Summary

| Term              | Meaning                                                                |
| ----------------- | ---------------------------------------------------------------------- |
| In-cache          | Data already loaded in CPU cache; fast to access.                      |
| Temporal locality | Access same data again soon.                                           |
| Spatial locality  | Access data near recently accessed data (like next elements in array). |
| Array benefit     | Arrays are contiguous → spatial locality → faster iteration.           |

---
