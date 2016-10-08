//C++ implementation of MaxHeap
#ifndef HEAP_H
#define HEAP_H

template <class T>
class MaxHeap
{
public:
    MaxHeap(int MaxHeapSize = 10);
    ~MaxHeap() { delete []heap; }
    int Size() const { return CurrentSize; }
    T Max()
    {
        //if(CurrentSize == 0)
        //    throw OutofBounds();
        return heap[1];
    }
    MaxHeap<T>& Insert(const T &x);
    MaxHeap<T>& DeleteMax(T &x);
    void Initialize(T a[], int size, int ArraySize);
    void Deactivate() { heap = 0; }
    void Output() const;

private:
    int CurrentSize, MaxSize;
    T *heap;
};

#endif
