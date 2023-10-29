public class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 }

class Solution
{
    public ListNode swapPairs(ListNode head){
        if (head== null || head.next == null) {
            return head; 
        }

        ListNode = firstNode = head;
        ListNode secondNode = head.next;
        Listnode remain = second.next;

        //swap 
        secondNode.next = firstNode;
        firstNode.next = swapPairs(remain);

        return secondNode;
    }
}