#include "NSort.h"

#include <algorithm>
#include <cassert>
#include <climits>
#include <vector>

static void expect_sorted(std::vector<int> values) {
    std::vector<int> expected = values;
    std::sort(expected.begin(), expected.end());

    sortn::sorts(static_cast<int>(values.size()), values.data());
    assert(values == expected);
}

int main() {
    expect_sorted({});
    expect_sorted({1});
    expect_sorted({2, 1});
    expect_sorted({5, 3, 3, 1, 5, 0, 2});
    expect_sorted({-5, -2, -10, -2, 0, 3, 1});
    expect_sorted({INT_MIN, 0, INT_MAX, -1, 1, INT_MIN, INT_MAX});

    // Sparse values exercise the std::sort fallback rather than a huge count array.
    expect_sorted({-1000000000, 7, 2000000000, -42, 999999999});

    // Repeated calls must not leak state between invocations.
    std::vector<int> first{4, 1, 2, 1};
    sortn::sorts(static_cast<int>(first.size()), first.data());
    assert((first == std::vector<int>{1, 1, 2, 4}));

    std::vector<int> second{-3, -1, -2};
    sortn::sorts(static_cast<int>(second.size()), second.data());
    assert((second == std::vector<int>{-3, -2, -1}));

    return 0;
}
