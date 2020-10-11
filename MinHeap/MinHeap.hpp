#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>

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

  friend std::ostream& operator<<(std::ostream& out, const MinHeap& mh) {
    if (mh.size == 0) {
      out << "[]";
      return out;
    }
    out << "[";
    out << mh.heap[1];
    for (int i = 2; i <= mh.size; i++)
      out << ", " << mh.heap[i];
    out << "]";
    return out;
  }
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
  size++;
  heap[size] = n;
  bubble_up(size);
}

int MinHeap::min() {
  if (empty())
    throw std::runtime_error("Heap is empty");
  return heap[0];
}

int MinHeap::extract_min() {
  if (empty())
    throw std::runtime_error("Heap is empty");
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
  if (i == 1)
    return;

  int p = parent(i);
  int val_i = heap[i];
  int val_p = heap[p];
  
  if (val_i < val_p) {
    heap[p] = val_i;
    heap[i] = val_p;
    bubble_up(p);
  }
}

void MinHeap::bubble_down(int i) {
  int l = left_child(i);
  if (l > size)
    return;

  int val_i = heap[i];
  int val_l = heap[l];
  int r = right_child(i);
  int val_r = heap[r];
  if (r > size && val_l < val_i) {
    heap[i] = val_l;
    heap[l] = val_i;
  } else if (val_i > val_l || val_i > val_r) {
    int val_r = heap[r];
    heap[i] = std::min(val_l, val_r);
    int min_ix = val_l < val_r ? l : r;
    heap[min_ix] = val_i;
    bubble_down(min_ix);
  }
}


#endif
