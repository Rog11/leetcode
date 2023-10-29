import java.util.LinkedList;

enum State  {Unvisited, Visited, Visiting}

boolean search(Graph g, Node start, Node end)
{
    if (start == end) return true;

    //operates as queue
    LinkedList<Node> q = new LinkedList<Node>();

    for (Node u: g.getNodes())
    {
        u.state = State.Unvisited;
    }
    start.state = State.Unvisiting;
    q.add(start);
    Node u;
    while(!q.isEmpty())
    {

    }
}


class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        
        for (int num : nums) {
            maxHeap.offer(num);
        }
        
        for (int i = 0; i < k - 1; i++) {
            maxHeap.poll();
        }
        
        return maxHeap.peek();
    }
}
