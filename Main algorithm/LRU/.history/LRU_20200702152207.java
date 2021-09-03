import java.util.*;

class Node{
    public int key, val;
    public Node prev, next = null;

    public Node(int k, int v){
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

    public int size(){
        return this.size;
    }
}

public class LRU{
    private HashMap<Integer, Node> map;
    private DoubleList cache;
    public int capacity;

    public LRU(int size){
        this.map = new HashMap<>();
        this.cache = new DoubleList();
        this.capacity = size;
    }

    public int get(int key){
        // if not such element
        if(!map.containsKey(key)){
            System.out.println("No such element");
            return -1;
        }else{
            // get the val and use put function to make it to be placed in the front
            int val = map.get(key).val;
            put(key, val);
            return val;
        }
    }

    public void put(int key, int val){
        Node temp = new Node(key, val);

        if(!map.containsKey(key)){
            if(cache.size == capacity){
                Node removed_ele = cache.removeLast();
                map.remove(removed_ele.key);
            }
            
            cache.addFirst(temp);
        }else{
            Node old = map.get(key);
            cache.remove(old);
            cache.addFirst(temp);
        }

        map.put(key, temp);

        return;
    }
}