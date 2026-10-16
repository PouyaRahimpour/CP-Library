
# Competitive Programming Library

A personal C++ library and template collection for competitive programming. It includes solution templates, local debugging utilities, algorithm and data-structure implementations, and examples for testlib-based generators, validators, and checkers.

- **Language:** C++20
- **Recommended starting template:** `template.cpp`
- **Local utilities:** `local.hpp`, `debug.hpp`
- **Testing library:** `testlib.h`

## Quick Start

### 1. Clone the repository

```bash
git clone https://github.com/PouyaRahimpour/CP-Library.git
cd CP-Library
```

Keep the repository in a stable location. You can write solutions in another directory and use the `-I` compiler option to include the library.

### 2. Create a solution

Copy the recommended template into your working directory.

```bash
cp template.cpp solution.cpp
```

Implement your solution inside `solve(int tc)`.


### 3. Compile and run locally

The following command enables local debugging, compiler warnings, and libstdc++ debug checks:

```bash
g++ -ggdb -DLOCAL -std=c++20 -O2 \
  -Wall -Wextra -Wshadow -Wformat=2 \
  -Wfloat-equal -Wconversion -Wlogical-op \
  -Wshift-overflow=2 -Wduplicated-cond \
  -Wcast-qual -Wcast-align \
  -Wno-unused-result -Wno-sign-conversion \
  -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC \
  -I/path/to/CP-Library \
  solution.cpp -o solution
```

Replace `/path/to/CP-Library` with the absolute path to your cloned repository.

For example, if your library is located at `/home/pouya/dev/CP-Library`, use:

```bash
-I/home/pouya/dev/CP-Library
```

Run your solution with a test input file:

```bash
./solution < input.txt
```

## Template Configuration

The template provides three source-level switches:

```cpp
#define TESTCASE
#define TIME
#define DEBUG
```

### `TESTCASE`

When enabled, the program reads the number of test cases before processing them.

```cpp
int t = 1;

#ifdef TESTCASE
cin >> t;
#endif

for (int i = 1; i <= t; i++) {
    Solve(i);
}
```

Comment out `#define TESTCASE` for problems that contain only one test case and do not provide `t`.

### `DEBUG`

When enabled in a local build, the `dbg(...)` macro prints variable names and values to standard error.

For example:

```cpp
int n = 5;
vector<int> a = {1, 2, 3, 4, 5};

dbg(n, a);
```

This lets you inspect intermediate values without adding temporary output to standard output. On the judge, the macro expands to nothing.

### `TIME`

Uncomment `#define TIME` to measure the execution time of each test case in a local build.

The timing helper reports elapsed time in seconds, with millisecond precision. Very short executions may consequently display as `0 sec`.

These switches are currently configured in the source file. You do not need to pass `-DDEBUG` or `-DTESTCASE` separately unless you decide to move the configuration into compiler flags.

In general, you shouldn't bother deleting colored output, as they are shown only locally.

## Local Utilities

### `local.hpp`

The local wrapper provides:

- The `Solve(int tc)` wrapper around `solve(int tc)`.
- Optional test-case banners.
- Optional per-test-case timing.
- The `dbg(...)` macro when debugging is enabled.
- Conditional integration with `testlib.h` for generator, validator, and checker builds.

### `debug.hpp`

The debug-printing utilities support common competitive-programming types, including:

- Scalars and strings.
- Pairs and tuples.
- Standard iterable containers.
- Nested containers.
- Stack, queue, and priority-queue-like structures.

Example:

```cpp
vector<vector<int>> graph = {
    {1, 2},
    {0, 3},
    {0},
    {1}
};

dbg(graph);
```

Debug output is sent to `std::cerr`, keeping it separate from the answer written to `std::cout`.

### `testlib.h`

The repository includes `testlib.h` for testlib-based tooling, such as randomized test generators, input validators, and custom checkers.

See the corresponding example files before adapting them to a specific problem.

## Other Repository Contents

### Algorithms and Data Structures
These files mostly exist because I wanted to think and learn by implementing from scratch. You shouldn't assume they are fully correct.

| File | Description |
| --- | --- |
| `BIT.cpp` | Fenwick tree / binary indexed tree. |
| `DSU.cpp` | Disjoint-set union (union-find). |
| `LCA.cpp` | Lowest common ancestor using binary lifting. |
| `SegmentTree.cpp` | Segment tree with a customizable information type. |
| `LazySegmentTree.cpp` | Lazy segment tree with customizable node and update types. |
| `SCC.cpp` | Strongly connected components and condensation graph. |
| `dijkstra.cpp` | Dijkstra's shortest-path algorithm. |
| `ordered_set.cpp` | GNU PBDS ordered sets/maps and order-statistics operations. |
| `RollingHash.cpp` | Polynomial rolling hash. |
| `Mint.cpp` | Modular arithmetic type. |
| `Z.cpp` | Additional number-theory and modular-arithmetic utilities. |
| `Q.cpp` | Rational-number type. |
| `Vector.cpp` | Fixed-dimensional vector operations. |
| `lll.cpp` | Input/output helpers for `__int128`. |
| `split.cpp` | String splitting utility. |

### Generators, Validators, and Checkers
These are a starting point for test and problem generation.
| File | Description |
| --- | --- |
| `generator.cpp` | Example testlib-based generator. |
| `validator.cpp` | Example input validator. |
| `checker.cpp` | Example custom checker. |



## License and Attribution

This is a personal competitive-programming library. Check individual source files for comments and attribution before reusing implementations. In particular, some implementations credit jiangly.

If you find a bug or have a suggestion, feel free to open an issue or pull request.
