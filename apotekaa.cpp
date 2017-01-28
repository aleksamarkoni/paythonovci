#include <iostream>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <algorithm>

using namespace std;

class priorityHeap {
  private:
    vector <int> heap;
    int levo(int parent);
    int desno(int parent);
    int parent(int child);
    void heapifyup(int index);
    void heapifydown(int index);
  public:
    priorityHeap() {}
    int size();
    void dodajElement(int element);
    void prikazHeapa();
    void sortiranje();
    int dajSledeci();
    void brisanjeNajmanjeg();
};

int priorityHeap::parent(int child) {
  int p = (child - 1) / 2;
  if(child == 0)
    return -1;
  else
    return p;
}

int priorityHeap::desno(int parent) {
  int r = 2 * parent + 2;
  if (r < heap.size())
    return r;
  else
    return -1;
}

int priorityHeap::levo(int parent) {
  int l = 2 * parent + 1;
  if (l < heap.size())
    return l;
  else
    return -1;
}

void priorityHeap::heapifyup(int in) {
  if (in >= 0 && parent(in) >= 0 && heap[parent(in)] > heap[in]) {
    int temp = heap[in];
    heap[in] = heap[parent(in)];
    heap[parent(in)] = temp;
    heapifyup(parent(in));
  }
}

void priorityHeap::heapifydown(int in) {
  int child = levo(in);
  int child1 = desno(in);
  if (child >= 0 && child1 >= 0 && heap[child] > heap[child1]) {
    child = child1;
  }
  if (child > 0 && heap[in] > heap[child]) {
    int temp = heap[in];
    heap[in] = heap[child];
    heap[child] = temp;
    heapifydown(child);
  }
}

int priorityHeap::size() {
  return heap.size();
}

void priorityHeap::dodajElement(int element) {
  heap.push_back(element);
  heapifyup(heap.size()-1);
}

void priorityHeap::prikazHeapa() {
  vector <int>::iterator pos = heap.begin();
  while (pos != heap.end()) {
    cout << *pos << " ";
    pos++;
  }
  cout << endl;
}

void priorityHeap::sortiranje() {
  sort(heap.begin(), heap.end());
}

void priorityHeap::brisanjeNajmanjeg() {
  if (heap.size() == 0) {
    cout << "Heap is empty" << endl;
    return;
  }
  heap[0] = heap.at(heap.size() - 1);
  heap.pop_back();
  heapifydown(0);
  cout << "Element Obrisan" << endl;
}

int priorityHeap::dajSledeci() {
  if (heap.size() == 0) {
    return -1;
  }
  else
    return heap.front();
}

int main() {
  priorityHeap h;
  int pacijent[10] = {1, 0, 2, 2, 4, 3, 4, 1, 2, 0};
  for (int i = 0; i < 10; i++) {
    h.dodajElement(pacijent[i]);
  }
  h.prikazHeapa();
  h.sortiranje();
  h.prikazHeapa();
  for (int i = 0; i < 10; i++) {
  cout<<"Najmanji Element:  "<<h.dajSledeci()<<endl;
  h.brisanjeNajmanjeg();
  h.sortiranje();
  h.prikazHeapa();
  }
}
