#include <stdbool.h>
#include <string>

bool is_palindrome(const char* str)
{
    int len = strlen(str);

    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
        {
            return false; 
        }
    }
    return true; 
}