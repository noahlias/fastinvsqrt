import time
from src import fast_inv_sqrt, fast_inv_sqrt_py

start_time = time.time()
for _ in range(100000):  # adjust the number of iterations as needed
    fast_inv_sqrt(25.0)  # or whatever number you want to test
print("fast_inv_sqrt took", time.time() - start_time, "seconds.")

start_time = time.time()
for _ in range(100000):  # adjust the number of iterations as needed
    fast_inv_sqrt_py(25.0)  # or whatever number you want to test
print("fast_inv_sqrt_py took", time.time() - start_time, "seconds.")
