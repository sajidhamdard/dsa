### **Kadane's Algorithm (Maximum Subarray Sum)**
Kadane’s Algorithm is used to find the **maximum sum of a contiguous subarray** in an array of integers.

#### **Algorithm Explanation**
1. Initialize:
   - `maxSum = Integer.MIN_VALUE` (to track the maximum sum found so far)
   - `currentSum = 0` (to store the current subarray sum)
   
2. Iterate through the array:
   - Add the current element to `currentSum`
   - If `currentSum` is greater than `maxSum`, update `maxSum`
   - If `currentSum` becomes negative, reset it to `0` (as a negative sum will not contribute to the maximum sum)

3. Return `maxSum` as the result.

#### **Java Implementation**
```java
public class KadaneAlgorithm {
    public static int maxSubarraySum(int[] nums) {
        int maxSum = Integer.MIN_VALUE;
        int currentSum = 0;

        for (int num : nums) {
            currentSum += num;
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
            if (currentSum < 0) {
                currentSum = 0; // Reset if sum becomes negative
            }
        }
        return maxSum;
    }

    public static void main(String[] args) {
        int[] arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        System.out.println("Maximum Subarray Sum: " + maxSubarraySum(arr));
    }
}
```

#### **Example Walkthrough**
For the input:  
`arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]`

Kadane's Algorithm runs as follows:
| Index | Element | Current Sum | Max Sum |
|--------|----------|----------------|------------|
| 0 | -2 | -2 | -2 |
| 1 | 1 | 1 | 1 |
| 2 | -3 | -2 | 1 |
| 3 | 4 | 4 | 4 |
| 4 | -1 | 3 | 4 |
| 5 | 2 | 5 | 5 |
| 6 | 1 | 6 | 6 |
| 7 | -5 | 1 | 6 |
| 8 | 4 | 5 | 6 |

#### **Final Answer:**  
The maximum sum subarray is `[4, -1, 2, 1]`, and the sum is **6**.

### **Time Complexity**
- **O(n)** (Iterates through the array once)
- **O(1) Space Complexity** (Uses only a few extra variables)

This is the optimal solution for the **Maximum Subarray Sum** problem. 🚀

[LeetCode reference] (https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solutions/4868897/most-optimized-kadane-s-algorithm-java-c-python-rust-javascript/)
