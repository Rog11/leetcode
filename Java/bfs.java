import java.util.LinkedList;
import java.util.Queue;
import java.util.List; 
import java.util.ArrayList;

class Node 
{
    boolean marked;
    int value; 
    List<Node> adjacent; 
    // Other properties and methods of the Node class
    public Node(int value)
    {
        this.value = value; 
        this.marked = false;
        this.adjacent = new ArrayList<>(); 
    }
}

public class bfs 
{
    public static void search(Node root) 
    {
        Queue<Node> queue = new LinkedList<>();
        root.marked = true;
        queue.add(root);

        while (!queue.isEmpty()) 
        {
            Node r = queue.poll();
            visit(r);

            for (Node n : r.adjacent) 
            {
                if (!n.marked) 
                {
                    n.marked = true;
                    queue.add(n);
                }
            }
        }
    }

    public static void visit(Node node) 
    {
        // Define what should be done when visiting a node
        // For example, you can print the node's value:
        System.out.println("Visiting node with value: " + node.value);
    }

    public static void main(String[] args) 
    {
        // Create your graph and nodes, and then call search() with the root node.
    }
}
