class node{
    public node next;
    public int val;

    public node(int val){
        this.val = val;
    }
}

class solution{
    node left;

    public boolean isPalidrom(node head){
        left = head;


    private boolean isPalidrom_helper(node right){
        if(head == null) return true;

        boolean result = isPalidrom(head.next);
        if 
    }
    }
}