### **90-Degree Rotation of a Matrix (Clockwise)**
To rotate an **N × N matrix** by **90 degrees clockwise**, follow these two simple steps:

---

### **Step 1: Transpose the Matrix**
- **Transposing** means flipping the matrix along its **main diagonal** (i.e., converting rows into columns).
- The **main diagonal** is where **row index = column index** (e.g., positions `(0,0)`, `(1,1)`, `(2,2)`, etc.).

#### **Example:**
Original matrix:
\[
\begin{bmatrix}
1 & 2 & 3 \\
4 & 5 & 6 \\
7 & 8 & 9
\end{bmatrix}
\]

After **transposing** (swap `matrix[i][j]` with `matrix[j][i]`):

\[
\begin{bmatrix}
1 & 4 & 7 \\
2 & 5 & 8 \\
3 & 6 & 9
\end{bmatrix}
\]

---

### **Step 2: Reverse Each Row**
- Now, **reverse** each row to get the **90-degree rotated matrix**.

Transposed matrix:
\[
\begin{bmatrix}
1 & 4 & 7 \\
2 & 5 & 8 \\
3 & 6 & 9
\end{bmatrix}
\]

After **reversing each row**:
\[
\begin{bmatrix}
7 & 4 & 1 \\
8 & 5 & 2 \\
9 & 6 & 3
\end{bmatrix}
\]

---

### **Java Code for 90-Degree Rotation**
```java
public class RotateMatrix {
    public static void rotate90Clockwise(int[][] matrix) {
        int n = matrix.length;

        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = temp;
            }
        }
    }

    public static void printMatrix(int[][] matrix) {
        for (int[] row : matrix) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int[][] matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        System.out.println("Original Matrix:");
        printMatrix(matrix);

        rotate90Clockwise(matrix);

        System.out.println("\nRotated Matrix (90 degrees clockwise):");
        printMatrix(matrix);
    }
}
```

---

### **Output**
```
Original Matrix:
1 2 3
4 5 6
7 8 9

Rotated Matrix (90 degrees clockwise):
7 4 1
8 5 2
9 6 3
```

---

### **Summary**
1. **Transpose the matrix** → Convert rows to columns.
2. **Reverse each row** → Move elements into their rotated positions.

This approach works in **O(N²) time complexity**, which is optimal for in-place rotation.
