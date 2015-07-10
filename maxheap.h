#ifndef MAX_HEAP_HEADER
#define MAX_HEAP_HEADER

template <class item>
class MaxHeap {
 public:
  MaxHeap(unsigned size = 256);

  unsigned size();
  void insert(item i);
  item pop();

 private:
  unsigned num_items;
  unsigned max_size;
  item* items;

  unsigned child(unsigned index, bool right);
  void heapify_up(unsigned child);
  void heapify_down(unsigned parent);
  unsigned parent(unsigned index);
  void swap(unsigned ind1, unsigned ind2);
};

#include "maxheap-inl.h"

#endif //MAX_HEAP_HEADER

