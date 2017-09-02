#include<stdio.h>
#include<stdlib.h>

#define MASK 0x80000000

int main()
{
	int num;

	printf("Enter an integer to check if its positive or negative\n");
	scanf("%d" ,&num);
	
	if(num & MASK)
		printf("Number is negative\n");
	else
		printf("Number is positive\n");
	return 0;
}
