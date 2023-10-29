class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k == 1) {
            return head;
        }

        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        ListNode curr = head;
        int count = 0;

        // Count the number of nodes in the list
        while (head != null) {
            count++;
            head = head.next;
        }

        while (count >= k) {
            ListNode first = curr;
            ListNode tail = prev;

            for (int i = 0; i < k; i++) {
                ListNode next = curr.next;
                curr.next = tail;
                tail = curr;
                curr = next;
            }

            prev.next = tail;
            first.next = curr;
            prev = first;
            count -= k;
        }

        return dummy.next;
    }
}
