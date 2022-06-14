/* File: buggy.c */
#include <stdio.h>

int foo(int a)
{
	printf("a=%d, %s:%d:%s\n ", a, __func__, __LINE__, __FILE__);
	printf("a=%d, %s:%d:%s\n ", a, __func__, __LINE__, __FILE__);
	printf("a=%d, %s:%d:%s\n ", a, __func__, __LINE__, __FILE__);
	printf("a=%d, %s:%d:%s\n ", a, __func__, __LINE__, __FILE__);
	printf("a=%d, %s:%d:%s\n ", a, __func__, __LINE__, __FILE__);
	return 0;
}


int main()
{
        int balance=100;
        int target=1000;
        float rate = 0.1;
        int year = 0;
        do
        {
                float interest = balance * rate;
                balance = balance + interest;
                year++;
        } while ( balance >= target );


	int b = 1234;
	foo(b);

        printf("%d No. of years to achieve target balance.\n", year);
        return 0;
}

