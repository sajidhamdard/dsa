### **What is Backtracking?**  
**Backtracking** is a **recursive algorithmic technique** used to solve problems by trying different possibilities and undoing (backtracking) choices when they lead to an incorrect or invalid solution.  

It's commonly used for problems where we need to **explore all possible solutions** and find one or more valid ones, such as:  
✔️ Finding all subsets of a set  
✔️ Generating permutations of a string  
✔️ Solving Sudoku, N-Queens, and Maze problems  

---

### **How Does Backtracking Work?**  
1. **Choose** → Pick an option from available choices.  
2. **Explore** → Recursively proceed with the choice.  
3. **Backtrack** → If the choice leads to an invalid solution, undo it and try the next possibility.  

**Key idea**: If a certain path is not leading to a solution, we **backtrack** and try a different approach.

---

### **Example: Generating All Subsets (Power Set)**
```java
import java.util.*;

public class BacktrackingExample {
    public static void generateSubsets(int[] arr, int index, List<Integer> subset) {
        // Print the current subset
        System.out.println(subset);

        // Explore all remaining elements
        for (int i = index; i < arr.length; i++) {
            subset.add(arr[i]); // Choose
            generateSubsets(arr, i + 1, subset); // Explore
            subset.remove(subset.size() - 1); // Backtrack (undo choice)
        }
    }

    public static void main(String[] args) {
        int[] arr = {1, 2};
        generateSubsets(arr, 0, new ArrayList<>());
    }
}
```
**Expected Output:**  
```
[]
[1]
[1, 2]
[2]
```
📌 **Why Backtracking?** → After choosing `1`, we explore all subsets including `1`. Then we backtrack (remove `1`) and try other possibilities.  

---

### **Where is Backtracking Used?**  
✔ **Subset generation** (Power Set)  
✔ **String permutations**  
✔ **Sudoku Solver**  
✔ **N-Queens Problem**  
✔ **Maze Solving (Rat in a Maze)**  
