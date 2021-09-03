class Node{
    public int key, val;
    public Node prev, next = null;

    public Node(int k, in v){
        this.key = k;
        this.val = v;
    }
}

class DoubleList{
    public Node head;
    public Node tail;
    public int size;

    public DoubleList(){
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    public void remove(Node x){

    }
}

public class LRU{

}