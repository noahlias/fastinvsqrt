from src import fast_inv_sqrt, fast_inv_sqrt_py


def benchmark():
    for _ in range(100000):  # 调整循环次数
        fast_inv_sqrt(25.0)

    for _ in range(100000):  # 调整循环次数
        fast_inv_sqrt_py(25.0)

if __name__ == "__main__":
    benchmark()