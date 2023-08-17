# Fast Inverse Square Root

!!! This is a experiment project for me to learn something about C extension on
Python.

## Getting Started

### Debug Locally

If you want to build extension without installing and just make a local test.

```sh
 python setup.py build_ext --inplace
```

### Build and Install

It will install in the site-packages directory, to find it with this command `python -m site --user-site`.

```python
 python setup.py build
 python setup.py install
```

## Enhanced the Debug

You should make a `CMakeList` to generate the _compiled_commands.json_ to
get the `clangd` or`ccls` language server support.

```text
cmake_minimum_required(VERSION 3.11)
project(project_name)

set(PYTHON_INCLUDE_DIRS "/pythonlib/include/python3.11")
set(PYTHON_LIBRARIES "/pythonlib/3.11/lib/libpython3.11.dylib")

include_directories(${PYTHON_INCLUDE_DIRS})

add_library(fast_inv_sqrt MODULE src/fast_inv_sqrt.c)
target_link_libraries(fast_inv_sqrt ${PYTHON_LIBRARIES})

set_target_properties(fast_inv_sqrt PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
	OUTPUT_NAME "fast_inv_sqrt"
	PREFIX ""
)

target_compile_options(fast_inv_sqrt PRIVATE -Wall -Wextra )
target_compile_options(fast_inv_sqrt PRIVATE -g)

```

Then generate the compiled commands json and you would find the references.

```sh
mdkir build && cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
make
```

## Benchmark

I use the `time` and [`viztracer`](https://github.com/gaogaotiantian/viztracer) and [`hyperfine`](https://github.com/sharkdp/hyperfine) to make benchmarks on three implementations on My **M1 Pro**.

- time
  ![Alt text](Assets/time.png)

- hyperfine
  ![Alt text](Assets/hyperfine.png)

## Inspire

- [Fast_Inverse_Square_Root](https://en.wikipedia.org/wiki/Fast_inverse_square_root)
- [Develop C Extension](https://docs.python.org/3/extending/extending.html)
- [swap_8_and_9](https://kenschutte.com/python-swap-ints/)
- [Benchmark](https://onestepcode.com/benchmarking-fast-inverse-square-root/)
