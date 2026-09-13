#include "NSort.h"

#include <algorithm>
#include <cstddef>
#include <vector>

namespace sortn {

void sorts(int n, int *array) {
    if (n <= 1 || array == nullptr) {
        return;
    }

    int min_value = array[0];
    int max_value = array[0];
    for (int i = 1; i < n; ++i) {
        min_value = std::min(min_value, array[i]);
        max_value = std::max(max_value, array[i]);
    }

    // Use long long so INT_MIN..INT_MAX cannot overflow while calculating the range.
    const long long range = static_cast<long long>(max_value) -
                            static_cast<long long>(min_value) + 1LL;

    // A counting array is useful only when the values are reasonably dense.
    // Fall back to std::sort for sparse inputs instead of allocating huge memory.
    const long long max_reasonable_range = static_cast<long long>(n) * 16LL + 1024LL;
    if (range <= 0 || range > max_reasonable_range) {
        std::sort(array, array + n);
        return;
    }

    std::vector<std::size_t> counts(static_cast<std::size_t>(range), 0);

    for (int i = 0; i < n; ++i) {
        const std::size_t index = static_cast<std::size_t>(
            static_cast<long long>(array[i]) - static_cast<long long>(min_value));
        ++counts[index];
    }

    int output = 0;
    for (std::size_t i = 0; i < counts.size(); ++i) {
        while (counts[i] != 0) {
            array[output++] = static_cast<int>(
                static_cast<long long>(min_value) + static_cast<long long>(i));
            --counts[i];
        }
    }
}

} // namespace sortn
