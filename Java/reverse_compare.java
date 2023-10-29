import java.util.LinkedList;

class LinkedListNode
{
    int data; 
    LinkedListNode next;

    public LinkedListNode(int data)
    {
        this.data = data;
        this.next = null;
    }
}

public class reverse_compare {
    boolean isPalindrome(LinkedListNode head) 
    {
        LinkedListNode reversed = reverseAndClone(head);
        return isEqual(head, reversed);
    }

    LinkedListNode reverseAndClone(LinkedListNode node)
    {
        LinkedListNode head = null; 
        while (node != null)
        {
            LinkedListNode n = new LinkedListNode(node.data); //clone
            n.next = head;
            head = n;
            node = node.next;
        }
        return head;
    }

    boolean isEqual(LinkedListNode one, LinkedListNode two)
    {
        while (one != null && two != null)
        {
            if (one.data != two.data)
            {
                return false;
            }
            one = one.next;
            two = two.next;
        }
        return one == null && two == null;
    }
}
