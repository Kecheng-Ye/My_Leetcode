import java.util.*;

public class problem2{

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */ 
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
        public String toString(){
            String ans = "";
            if(next == null) return ans + val;
            return ans + val + next.toString();
        }
    }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        int who_ends = 0;
        ListNode final_ans = new ListNode(0);
        ListNode temp = final_ans;

        
        while(who_ends == 0 || carry > 0){   // if none of the lists reach end or there is still a carry we have to deal with
            int x = (l1 == null) ? 0 : l1.val;   //if either list has reach end this turn we will assign the default value 0 to it
            int y = (l2 == null) ? 0 : l2.val;
            int sum = (carry > 0) ? x + y + 1 : x + y;
            carry = (sum >= 10) ? 1 : 0;
            sum %= 10;             //we will only deal the single digit of the sum and leave the tens digit to the next iteration
            

            ListNode one_digit = new ListNode(sum);
            temp.next = one_digit;
            temp = temp.next;
            l1 = (l1 == null) ? null : l1.next;
            if(l1 == null) {    //if l1 reach ends first
                who_ends = 1;
            }
            l2 = (l2 == null) ? null : l2.next;
            if(l2 == null) {   //if l2 reach ends first
                who_ends = 2;
            }
        }
        //since one list has been run out, we will connect the whole number of the other list to the ans
        //EX: ->9 + ->1->3->4  =  ->0->4->(->4)
        temp.next = (who_ends == 1) ? l2: l1;   
        return final_ans.next;
    }

    public static void main(String[] args) {
        ListNode node1 = new ListNode(1);
        // node1.next = new ListNode(2);
        // node1.next.next = new ListNode(3);
        // node1.next.next.next = null;

        ListNode node2 = new ListNode(9);
        node2.next = new ListNode(9);
        // node2.next.next = new ListNode(1);

        // System.out.println(node1);
        System.out.println(addTwoNumbers(node1, node2));

    }

}