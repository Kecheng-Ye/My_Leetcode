public class heap <Key extends Comparable<Key>>{
    private Key[] heap;
    public int size;

    public heap(int capacity){
        heap = (Key[]) new Comparable[capacity + 1];
    }

    private int parent(int index){return (int)index/2;}

    private int left(int index){return index * 2;}

    private int right(int index){return index * 2 + 1;}

    public Key max(){
        return heap[1];
    }

    public void insert(Key e){
        size ++;
        heap[size] = e;
        swim(size);
    }

    public Key delMax(){
        Key ans = max();
        exch(1, size);
        heap[size] = null;
        size --;
        sink(1);

        return ans;
    }

    private void swim(int k) {
        int i = k;
        while(i >= 1 && less(parent(i), i)){
            exch(parent(i), i);
            i = parent(i);
        }
    }

    private void sink(int k){
        while(left(k) <= size){
            int big_child = left(k);
            if(right(k) <= size && less(big_child, right(k))) big_child = right(k);
            if(less(big_child, k)) break;

            exch(big_child, k);
            k = big_child;
        }
    }
    
    private void exch(int i, int j) {
        Key temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    private boolean less(int i, int j) {
        if(heap[i] == null) return true;
        if(heap[j] == null) return false;

        return heap[i].compareTo(heap[j]) < 0;
    }
    
    
}