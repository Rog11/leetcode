
public class isPermutation 
{
    public static boolean Permutation (String str1, String str2) 
    {
        if (str1.length() != str2.length())
        {
            return false; 
        }
        int[] charCounts = new int[256];

        for (char c: str1.toCharArray())
        {
            charCounts[c]++;
        }
    
        for (char c: str2.toCharArray())
        {
            charCounts[c]--;
        }

        for (int i = 0; i < 256; i++)
        {
            if (charCounts[i] != 0)
            {
                return false;
            }
        }
        return true; 
    }

    public static void main(String[] args)
    {
        String str1 = "ehllo";
        String str2 = "hello";

        boolean Permutation = Permutation(str1, str2);

        System.out.println(Permutation);
    }
}




