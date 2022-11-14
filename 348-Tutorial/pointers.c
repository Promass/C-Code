#include <stdio.h>

int main() {
	const int j = 2;
    int i = 1;
    const int * p;
    int const * p2;
    int * const p3;
    int * p4;

    p2 = &j;
    *p2;
    //(*p2)++; Invalid
    //p3 = &i; Invalid
    p++;
    //(*p)++; Invalid

    void * ptr;
    int test = 8;
    (int *)ptr = &test;

    int pop = *ptr;

    printf("%d\n", pop);
    printf("Success\n");

    return 0;
}