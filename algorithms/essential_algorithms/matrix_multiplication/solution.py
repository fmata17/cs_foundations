def matrix_mul(m1: list[list[int]], m2: list[list[int]]):
    """Standard triple loop algorithm for matrix dot product."""
    q1 = len(m1[0])     # columns of m1
    q2 = len(m2)        # rows of m2

    if q1 == q2:
        p = len(m1)     # rows of m1
        q = q1          # shared dimension
        r = len(m2[0])  # columns of m2

        m3 = [[0] * r for _ in range(p)]  # initialize a p x r result matrix

        for i in range(p):      # O(n^3)?
            m3_row = [0 for _ in range(r)]
            for j in range(r):
                for k in range(q):
                    m3_row[j] += m1[i][k] * m2[k][j]
            m3[i] = m3_row

    else:
        print("Dimension mismatch!")
        return

    return m3


matrix1 = [[2, -1, 4],  # p x q
           [0, 3, 5]]

matrix2 = [[1, 0],  # q x r
           [2, -2],
           [3, 1]]

print(matrix_mul(matrix1, matrix2))
