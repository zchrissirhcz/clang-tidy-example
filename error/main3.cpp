#include <stdio.h>

int max(int x, int y)
{
    return x > y ? x : y;
}

int min(int x, int y)
{
    return x < y ? x : y;
}

int add(int x, int y)
{
    return x + y;
}

int my_abs(int x)
{
    return x > 0 ? x : -x;
}

int process(int x, int y, int(*f)())
{
    return (*f)(x, y);
}

int main()
{
    int a = 3;
    int b = 4;
    int c = process(a, b, my_abs);
    printf("c = %d\n", c);

    return 0;
}