public class heap <Key extends Comparable<Key>>{
    private Key[] heap;
    public int size;

    public heap(){}

    private int parent(int index){return (int)index/2;}

    private int left(int index){return index * 2;}

    private int right(int index){return index * 2 + 1;}

    
    
}