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
        return;
    }

    private void swim(int k) {
        int i = k;
        while(i >= 1 && less(parent(i), i)){
            exch(parent(i), i);
            i = parent(i);
        }
    }

    private void sink(int k){
        
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