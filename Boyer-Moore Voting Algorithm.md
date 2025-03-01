### **Boyer-Moore Voting Algorithm**

The **Boyer-Moore Voting Algorithm** is an **efficient algorithm** for finding the **majority element** in an array in **O(n) time** and **O(1) space**.

---

### **How It Works**

1. **Candidate Selection:**
   - We maintain a **candidate** for the majority element and a **count**.
   - Start with the first element as the candidate and count = 1.
2. **Counting Votes:**

   - Traverse the array:
     - If the current element matches the candidate, **increase count**.
     - If it does not match, **decrease count**.
     - If count reaches 0, **update the candidate** to the current element and reset count to 1.

3. **Final Majority Check:**
   - If we are guaranteed that a majority element exists (appearing more than `n/2` times), the candidate at the end will be the majority element.

---

### **Code Implementation**

```java
class Solution {
    public int majorityElement(int[] nums) {
        int candidate = nums[0], count = 1;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == candidate) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    candidate = nums[i];
                    count = 1;
                }
            }
        }

        return candidate;
    }
}
```

---

### **Example Walkthrough**

#### **Input:**

```java
nums = [2,2,1,1,1,2,2]
```

#### **Step-by-Step Execution**

| Index | Element | Candidate | Count | Action                             |
| ----- | ------- | --------- | ----- | ---------------------------------- |
| 0     | 2       | 2         | 1     | Initial candidate                  |
| 1     | 2       | 2         | 2     | +1 (Same as candidate)             |
| 2     | 1       | 2         | 1     | -1 (Different from candidate)      |
| 3     | 1       | 2         | 0     | Count = 0, Change candidate to `1` |
| 4     | 1       | 1         | 1     | +1 (Same as candidate)             |
| 5     | 2       | 1         | 0     | Count = 0, Change candidate to `2` |
| 6     | 2       | 2         | 1     | +1 (Same as candidate)             |

#### **Final Majority Element:** `2`

---

### **Time and Space Complexity**

✅ **Time Complexity:** `O(n)` (Single pass through the array)  
✅ **Space Complexity:** `O(1)` (No extra storage used)

---

### **Why It Works?**

- Since the majority element appears **more than `n/2` times**, the other elements **cannot cancel it out completely**.
- Even if it gets reset, it will be chosen again because of its dominance.

---

### **When to Use Boyer-Moore?**

✅ When a majority element **is guaranteed to exist**  
✅ When you need **O(n) time complexity** and **O(1) space complexity**

🚀 **Let me know if you need any clarification!**
