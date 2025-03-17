The **Pigeonhole Principle** is a simple but powerful mathematical concept that states:  

> **If you place more items into fewer containers than the number of items, at least one container must hold more than one item.**  

### **Example 1: Basic Pigeonhole Principle**  
- Suppose you have **4 pigeons** and **3 pigeonholes**.  
- If each pigeon goes into a hole, at least **one pigeonhole must contain more than one pigeon**.  

This principle is used in various areas of mathematics and computer science.

---

### **Example 2: Applying It to the ⌊n/3⌋ Majority Element Problem**
- We are looking for elements that appear **more than ⌊n/3⌋ times**.
- If there were **3 or more** such elements, their total count would be **greater than n**.
- This **violates** the constraint that the array has only `n` elements.
- Thus, there can be **at most 2** such elements.

This is why in the **Boyer-Moore Majority Voting Algorithm** for **⌊n/3⌋**, we track **only 2 candidates**. 🚀
