class ListNode{
    public ListNode next;
    public int val;

    public ListNode(int val){this.val = val;}
}

public class reverse{
    public ListNode reverse(ListNode a) {
        ListNode pre, cur, next;
        pre = null;
        cur = next = a;

        while(cur != null){
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }

    public ListNode reverse(ListNode a, ListNode b){
        ListNode pre, cur, next;
        pre = null;
        cur = next = a;

        while(cur != b){
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
}