/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
          if(head ==null || (head.next==null) )
            return head;
        ListNode h_odd = head;
        ListNode h_even = head.next;;
        ListNode odd = h_odd;
        ListNode even = h_even;
        
        while(even != null){
            if(even.next != null)
                odd.next= even.next;
            else{
                odd.next= h_even;
                return h_odd;
            }
            odd=odd.next;
            even.next= odd.next;
            even = even.next;
            }
        odd.next = h_even;
        return h_odd;
        
    }
}