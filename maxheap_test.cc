#include <algorithm>
#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "maxheap.h"

using std::vector;

TEST(MaxHeap, sanity) {
  MaxHeap<int> mh(256);
  mh.insert(5);
}

TEST(MaxHeap, insertpop) {
  int size = 1024;
  MaxHeap<int> mh1(size/4);
  MaxHeap<int> mh2(size/4);
  for (int i = 0; i < size; i++) {
    mh1.insert(i);
    mh2.insert(size-1-i);
  }
  for (int i = size-1; i >= 0; i--) {
    EXPECT_EQ(mh1.pop(), i);
    EXPECT_EQ(mh2.pop(), i);
  }
}

TEST(MaxHeap, depth3_full_test) {
  int combos = 1 << 15;
  for (int encoding = 0; encoding < combos; encoding++) {
    int values[7];
    for (int i = 0; i < 7; i++) {
      values[i] = (encoding >> 2*i) & 4;
    }

    // Insert into a maxheap and vector at the same time.
    vector<int> check;
    MaxHeap<int> mh1(64);
    for (int i = 0; i < 7; i++) {
      check.push_back(values[i]);
      mh1.insert(check[i]);
    }
    std::sort(check.begin(), check.end(), std::greater<int>());

    // Verify the max value is removed at all times.
    for (int i = 0; i < 7; i++) {
      EXPECT_EQ(mh1.pop(), check[0]);
      check.erase(check.begin());
    }
  }
}
