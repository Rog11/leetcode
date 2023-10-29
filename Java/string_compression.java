import java.util.Arrays;

public class string_compression{
    public static int compression (char[] chars)
    {
        int i= 0, j = 0; 

        while(i < chars.length)
        {
            int count = 1; 
            while (i + 1 < chars.length && chars[i] == chars[i+1])
            {
                count++;
                i++;
            }
            // if (count == 1)
            // {
                chars[j++] = chars[i];
                // }
            if (count > 1)
            {
                char[] countChars = String.valueOf(count).toCharArray();
                for (char c: countChars)
                {
                    chars[j++] = c;
                }
                i++;
            }
        }
        return j; 
    }
    public static void main(String[] args)
    {
        char[] chars = "aabbbbccccc".toCharArray();

        int newLength = compression(chars);

        System.out.println(newLength); 
        System.out.println(new String(chars, 0, newLength));
    }
}
