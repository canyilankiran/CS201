#include "AlgorithmSortHeap.h"

using namespace std;

AlgorithmSortHeap::AlgorithmSortHeap(int k): SelectionAlgorithm(k) {

}
int AlgorithmSortHeap::select() {
    int N;
    cin >> N;
    BinaryHeap *heap = new BinaryHeap(k);
    for (int i = 0; i < k; i++) {
        int b;
        cin>>b;
        heap->insert(b);
    }
    int j=N-k;
    while (j-- > 0) {
        int x;
        cin>>x;
        if (x < heap->getMin()) {
            continue;
        }else{
            heap->deleteMin();
            heap->insert(x);
        }
    }
    return heap->getMin();
}
