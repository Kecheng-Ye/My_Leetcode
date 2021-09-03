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

    public void addFirst(Node x){
        if(size == 0){
            head = x;
            tail = x;
        }else{
            head.prev = x;
            x.next = head;
            head = x;
        }

        size ++;
    }

    public void remove(Node x){
        x.prev.next = x.next;
        x.next.prev = x.prev;   

        x.prev = null;
        x.next = null;
        
        size --;
    }

    public Node removeLast(){
        Node temp = tail;
        tail.prev.next = null;
        tail = tail.prev;
        tail.prev = null;
        return temp;

    }
}

public class LRU{

}