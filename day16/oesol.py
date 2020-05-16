# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if(head == None or head.next== None):
            return head
        h_odd = head
        h_even = head.next
        odd = h_odd
        even = h_even
        
        while(even != None):
            if(even.next != None):
                odd.next= even.next
            else:
                odd.next= h_even
                return h_odd
            
            odd=odd.next
            even.next= odd.next
            even = even.next
          
        odd.next = h_even
        return h_odd
        