#ifndef MIN_HEAP_H
#define MIN_HEAP_H

class MinHeap {
  int* heap;
  int size;
  int capacity;
  void bubble_up(int);
  void bubble_down(int);
  int parent(int);
  int left_child(int);
  int right_child(int);
public:
  MinHeap(int);
  int min();
  int extract_min();
  void insert(int);
  bool empty();
  bool full();
};

MinHeap::MinHeap(int cap): capacity(cap), size(0), heap(new int[cap]) { }

int MinHeap::parent(int i) {
  return i / 2;
}

int MinHeap::left_child(int i) {
  return 2 * i;
}

int MinHeap::right_child(int i) {
  return 2 * i + 1;
}

void MinHeap::insert(int n) {
  if (full())
    throw std::runtime_error("Heap is full");
  heap[size] = n;
  bubble_up(size++);
}

int MinHeap::min() {
  if (empty())
    throw std::runtime_error("Heap is full");
  return heap[0];
}

int MinHeap::extract_min() {
  if (empty())
    throw std::runtime_error("Heap is full");
  int min = heap[0];
  heap[0] = heap[--size];
  bubble_down(0);
  return min;
}

bool MinHeap::empty() {
  return size == 0;
}

bool MinHeap::full() {
  return size == capacity;
}

void MinHeap::bubble_up(int i) {
  // todo
}

void MinHeap::bubble_down(int i) {
  // todo
}


#endif
