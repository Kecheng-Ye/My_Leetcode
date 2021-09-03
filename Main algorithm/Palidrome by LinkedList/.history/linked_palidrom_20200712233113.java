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
        
    }

    private boolean isPalidrom_helper(node right){
        if(right == null) return true;

        
        if(!(isPalidrom_helper(right.next) && (left.val == right.val))) return false;
        left = left.next;
        return true;
    }
}