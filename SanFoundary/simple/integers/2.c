#include<stdio.h>
#include<stdlib.h>

#define MASK 0x1

int sum(int num,int inc)
{
	return num + inc;
}

int main()
{
	int i,esum=0,osum=0;
	long num;

	printf("Enter a number whose all sums of even and odd needs to be published\n");
	scanf("%lu" ,&num);
	
	if(num < 1 || num > 2147483648)
		printf("Enter a valid integer from 1 to %lu\n" ,2147483648);
	else
	{
		for(i=2;i<=num;i++)
		{
			if(i & MASK)
				osum = sum(osum,i);
			else
				esum = sum(esum,i);
		}
		printf("Sum of even numbers from 1 till %lu is %d\n" ,num,esum);
		printf("Sum of odd numbers from 1 till %lu is %d\n" ,num,osum);
	}

	return 0;
}
