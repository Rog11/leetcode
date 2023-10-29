import java.util.Arrays; 



public class rotate_left {
    public static void main(String[] args)
    {
        int[] a = {1,2,3,4,5};
        int d = 4; 
        int[] rotatedArray = rotLeft(null, 0);
    }

    static int[] rotLeft (int[] a, int d) 
    {
        int[] tempArray = new int[a.length];

        for (int i = 0; i < a.length; i++)
         {
            int newIndex = (i + d) % a.length;
            tempArray[i] = a[newIndex];
        }

       return tempArray;
    }
}

