#include <stdio.h>

//s,d,e represnts three pegs 
//(source, destination, extra)
//n is number of discs (all initially in s)

void towerOfHanoi(char s, char d, char e, int n)
{
    //terminating condition
    if (n <= 0)
        return; 
    towerOfHanoi(s,e,d,n-1);
    printf("Move Disk %d from %c to %c\n", n,s,d); 
    towerOfHanoi(e,d,s,n-1); 
}
int main()
{
    towerOfHanoi('s','d','e',3); 
}