import java.util.Comparator;
import java.util.PriorityQueue;

public class findkth_largest {
    public int findkthLargest(int nums, int k)
    {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());

        for (int num: nums)
        {
            maxHeap.offer(num);
        }

        for (int i = 0; i < k-1; i++)
        {
            maxHeap.poll();
        }
        return maxHeap.peek(); 
    }
}
