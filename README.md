# OwnSortingAlgorithm

`sortn::sorts` is an integer sorting implementation based on a counting/range-sort approach.

## Complexity

For a dense value range of size `K`:

- Time: **O(N + K)**
- Auxiliary space: **O(K)**

The implementation first finds the minimum and maximum values and normalizes values relative to the minimum, so negative integers are handled without a separate negative array.

For sparse inputs where the value range would be disproportionately large, the implementation falls back to `std::sort` to avoid excessive memory allocation. This makes the function safe for arbitrary `int` values, including `INT_MIN` and `INT_MAX`.

## Usage

```cpp
#include "NSort.h"

int values[] = {5, -2, 3, -2, 0, 1};
sortn::sorts(6, values);
// values is now {-2, -2, 0, 1, 3, 5}
```

## Tests

The CMake project includes regression tests covering:

- empty and single-element inputs
- duplicates
- positive and negative integers
- `INT_MIN` / `INT_MAX`
- sparse ranges that trigger the fallback
- repeated calls without shared state leaking between invocations

Build and run them with:

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```
