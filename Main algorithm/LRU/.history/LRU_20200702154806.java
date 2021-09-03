import java.util.*;

class Node{
    public int key, val;
    public Node prev, next = null;

    public Node(int k, int v){
        this.key = k;
        this.val = v;
    }

    public String toString(){
        return "( " + key + " " + val + " )";
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
        if(x == head){
            head = x.next;
            head.prev = null;
        }else if(x == tail){
            tail = x.prev;
            tail.next = null;
        }else{
            x.prev.next = x.next;
            x.next.prev = x.prev;
        }

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

    public String toString(){
        String ans = "[ ";
        
        Node temp = head;
        while(temp != null){
            ans += temp.toString();
            temp = temp.next;
        }

        ans += " ]";

        return ans;
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

        // if the LRU does not orginally contain the element
        if(!map.containsKey(key)){
            // check the cache size first
            // remove the least recently used element if necessary
            if(cache.size == capacity){
                Node removed_ele = cache.removeLast();
                map.remove(removed_ele.key);
            }
            // add the new element to the front
            cache.addFirst(temp);
        }else{
            // if cache contains the key
            // remove the older one
            // add the new one to the front
            Node old = map.get(key);
            cache.remove(old);
            cache.addFirst(temp);
        }
        // remember to update the map
        map.put(key, temp);

    }

    public String toString(){
        return cache.toString();
    }

    public static void main(String[] args) {
        LRU cache = new LRU(2);
        cache.put(1, 1);
        System.out.println(cache);
        // cache = [(1, 1)]
        cache.put(2, 2);
        System.out.println(cache);
        // cache = [(2, 2), (1, 1)]
        System.out.println("cache.get(1) = " + cache.get(1));       // 返回 1
        System.out.println(cache);
        // cache = [(1, 1), (2, 2)]
        // 解释：因为最近访问了键 1，所以提前至队头
        // 返回键 1 对应的值 1
        cache.put(3, 3);
        System.out.println(cache);
        // cache = [(3, 3), (1, 1)]
        // 解释：缓存容量已满，需要删除内容空出位置
        // 优先删除久未使用的数据，也就是队尾的数据
        // 然后把新的数据插入队头     
        System.out.println("cache.get(2) = " + cache.get(2));       // 返回 -1
        System.out.println(cache);
        // cache = [(3, 3), (1, 1)]
        // 解释：cache 中不存在键为 2 的数据
        cache.put(1, 4);   
        System.out.println(cache); 
        // cache = [(1, 4), (3, 3)]
        // 解释：键 1 已存在，把原始值 1 覆盖为 4
        // 不要忘了也要将键值对提前到队头
        
    }
}