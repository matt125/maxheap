template <class item>
MaxHeap<item>::MaxHeap(unsigned size) {
  num_items = 0;
  max_size = size;
  items = new item[max_size];
}

template <class item>
unsigned MaxHeap<item>::parent(unsigned index) {
  return index/2 - (index % 2 == 0);
}

template <class item>
unsigned MaxHeap<item>::child(unsigned index, bool right) {
  return index * 2 + 1 + right;
}

template <class item>
void MaxHeap<item>::insert(item i) {
  // Expand the heap if necessary.
  if (num_items == max_size) {
    item* old_items = items;
    items = new item[max_size * 2];
    for (unsigned i = 0; i < max_size; i++) {
      items[i] = old_items[i];
    }
    delete old_items;
    max_size <<= 1;
  }
  items[num_items] = i;
  num_items++;
  heapify_up(num_items-1);
}


template <class item>
void MaxHeap<item>::swap(unsigned ind1, unsigned ind2) {
  item temp = items[ind1];
  items[ind1] = items[ind2];
  items[ind2] = temp;
}

template <class item>
item MaxHeap<item>::pop() {
  if (num_items == 0) {
    throw std::out_of_range("No items in heap\n");
  }
  item ret = items[0];
  items[0] = items[num_items-1];
  num_items = num_items-1;
  heapify_down(0);
  return ret;
}

template <class item>
void MaxHeap<item>::heapify_down(unsigned parent) {
  unsigned left = child(parent, false);
  unsigned right = child(parent, true);

  if (left >= num_items) {
    return;
  } else if (right >= num_items) {
    if (items[left] > items[parent]) {
      swap(left, parent);
      return heapify_down(left);
    }
  } else {
    if (items[left] > items[parent] && items[left] >= items[right]) {
      swap(left, parent);
      return heapify_down(left);
    } else if (items[right] > items[parent]) {
      swap(right, parent);
      return heapify_down(right);
    }
  }
}

template <class item>
void MaxHeap<item>::heapify_up(unsigned child) {
  if (child == 0) {
    return;
  }

  unsigned par = parent(child);
  if (items[child] > items[par]) {
    item temp = items[child];
    items[child] = items[par];
    items[par] = temp;
    heapify_up(par);
  }
}

template <class item>
unsigned MaxHeap<item>::size() {
  return num_items;
}
