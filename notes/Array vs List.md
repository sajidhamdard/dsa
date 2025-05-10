### **📌 Array vs List in Data Structures**

In data structures, **Array** and **List** are both used to store collections of elements, but they have key differences in terms of **size, memory, and operations**.

---

## **1️⃣ Array (Fixed Size)**

🔹 **Fixed-size**: Must define the size at initialization.  
🔹 **Stored in contiguous memory locations** → Fast access.  
🔹 **Direct index-based access (O(1))**.  
🔹 **Insertion & Deletion** at arbitrary positions is **slow (O(n))** because shifting is required.  
🔹 **Memory-efficient** but **cannot grow dynamically**.

### **✅ Example: Array in Java**

```java
int[] arr = new int[5]; // Fixed size
arr[0] = 10;
arr[1] = 20;
System.out.println(arr[1]); // Output: 20
```

---

## **2️⃣ List (Dynamic Size)**

🔹 **Can grow/shrink dynamically**.  
🔹 **Elements are stored as nodes (LinkedList) or in resizable arrays (ArrayList)**.  
🔹 **Slower access (O(n))** in LinkedList but **O(1) in ArrayList**.  
🔹 **Insertion & Deletion** at arbitrary positions is **faster in LinkedList (O(1))** but **slower in ArrayList (O(n))**.  
🔹 **Uses extra memory** for pointers (in LinkedList).

### **✅ Example: List in Java**

```java
import java.util.*;

List<Integer> list = new ArrayList<>();
list.add(10);
list.add(20);
System.out.println(list.get(1)); // Output: 20
```

---

## **🔹 Array vs List Comparison Table**

| Feature                | **Array**                | **List (LinkedList & ArrayList)**     |
| ---------------------- | ------------------------ | ------------------------------------- |
| **Size**               | Fixed                    | Dynamic                               |
| **Memory Usage**       | Less (No extra overhead) | More (Extra pointers in LinkedList)   |
| **Access Time**        | O(1) (Direct Index)      | O(1) in ArrayList, O(n) in LinkedList |
| **Insertion (Middle)** | O(n) (Shifting Required) | O(1) in LinkedList, O(n) in ArrayList |
| **Deletion (Middle)**  | O(n)                     | O(1) in LinkedList, O(n) in ArrayList |
| **Usage**              | When size is known       | When dynamic resizing is needed       |

---

## **🔹 When to Use What?**

✅ **Use Arrays** when:  
✔ You need **fast access (O(1))**.  
✔ The size is **known and fixed**.  
✔ You want **low memory overhead**.

✅ **Use Lists** when:  
✔ The size **changes frequently**.  
✔ You need **fast insertions/deletions (LinkedList)**.  
✔ You need **dynamic memory allocation**.
