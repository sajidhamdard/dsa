### **Power Set Algorithm (Generating All Subsets of a Set)**  
The **Power Set** of a set **S** is the set of **all possible subsets**, including:  
- The **empty set** `[]`
- The **original set** itself
- All possible combinations of elements  

#### **Example: Power Set of `{1, 2}`**  
```
Power Set: [ [], [1], [2], [1, 2] ]
```

#### **Example: Power Set of `{1, 2, 3}`**  
```
Power Set: [ [], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3] ]
```

---

### **Two Approaches for Power Set Generation**

#### **1️⃣ Using Backtracking (Recursive Approach)**
We use recursion to explore all possible subsets **by either including or excluding** each element.  

```java
import java.util.*;

public class PowerSetBacktracking {
    public static void generatePowerSet(int[] arr, int index, List<Integer> subset) {
        // Print the current subset (this line executes for all possible subsets)
        System.out.println(subset);

        // Explore all remaining elements
        for (int i = index; i < arr.length; i++) {
            subset.add(arr[i]); // Choose: Add element
            generatePowerSet(arr, i + 1, subset); // Explore: Recur with the next index
            subset.remove(subset.size() - 1); // Backtrack: Remove last element
        }
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3};
        generatePowerSet(arr, 0, new ArrayList<>());
    }
}
```

**🔹 How It Works?**  
- Start with an empty subset `[]`.  
- Try including each element one by one and explore.  
- Backtrack to explore other possibilities.  

✅ **Time Complexity:** `O(2ⁿ)` (Each element can be either included or not)  
✅ **Space Complexity:** `O(n)` (Recursion stack)  

---

#### **2️⃣ Using Bit Manipulation (Iterative Approach)**
Since each element can be either **included (1)** or **excluded (0)**, we can generate subsets using **binary representation**.

```java
import java.util.*;

public class PowerSetBitwise {
    public static void generatePowerSet(int[] arr) {
        int n = arr.length;
        int totalSubsets = 1 << n; // 2^n subsets

        for (int i = 0; i < totalSubsets; i++) {
            List<Integer> subset = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) { // Check if jth bit is set
                    subset.add(arr[j]);
                }
            }
            System.out.println(subset);
        }
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3};
        generatePowerSet(arr);
    }
}
```

**🔹 How It Works?**  
- We generate all numbers from `0` to `2ⁿ - 1` (binary representation).  
- Each `bit` in a number determines whether to include a particular element.  

✅ **Time Complexity:** `O(2ⁿ * n)`  
✅ **Space Complexity:** `O(1)`  

---

### **Which Approach Should You Use?**
| **Approach**       | **Use Case** |
|------------------|-------------|
| **Backtracking** | Easy to understand, good for interview practice |
| **Bit Manipulation** | More optimized for large input sets |
