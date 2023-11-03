#include <stdio.h>

char display(char x)
{
    if ( < 0) 
    {
        return (0);
    }
    printf("%d", x);
    display(x - 1);
    return (x);
}

int main(void)
{
    display(4);
    return 0;;
}
