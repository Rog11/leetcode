#include <stdio.h>


int power(int x, int n)
{
    if (n == 0)
        return 1; 
    else if (1 == x)
        return x; 
    else 
        return x * power(x, n-1); 

}

int main()
{
    printf("%d", power(1, 2)); 
}