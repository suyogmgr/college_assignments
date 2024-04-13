import numpy as np

def wolfe_decomposition(A, b, c, D, d, x, pi, tol):
    n = len(b)
    for i in range(n):
        for j in range(n):
            if i == j:
                pi[i] = c[i]
            else:
                pi[i] = 0
        ck = sum(A[i][j] * pi[j] for j in range(n))
        ak = b[i] - ck
        cBBinv = sum(D[i][j] * pi[j] for j in range(n))
        barcs = sum(ak[j] * cBBinv for j in range(n))
        if abs(barcs) < tol:
            x = [xi + ak[i] * cBBinv for i, xi in enumerate(x)]
    return x

def main():
    n = 10
    A = [list(map(float, input(f"Enter row {i+1} of A: ").split())) for i in range(n)]
    b = [float(input(f"Enter b{i+1}: ")) for i in range(n)]
    D = [list(map(float, input(f"Enter row {i+1} of D: ").split())) for i in range(n)]
    d = [float(input(f"Enter d{i+1}: ")) for i in range(n)]
    c = [float(input(f"Enter c{i+1}: ")) for i in range(n)]
    x = [0.0] * n
    pi = [0.0] * n
    tol = 0.001
    x = wolfe_decomposition(A, b, c, D, d, x, pi, tol)
    print("The solution is:")
    for i, xi in enumerate(x):
        print(f"x[{i}] = {xi:.4f}")


main()
print("Suyog Rana Magar")