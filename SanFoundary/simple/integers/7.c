#include<stdio.h>
#include<stdlib.h>

int sum(int num)
{
	int sum=0;
	while(num)
	{
		sum = sum + (num%10);
		num/=10;
	}
	return sum;
}

int main()
{
	int num;

	printf("Enter a number whose sum of digits needs to be computed\n");
	scanf("%d", &num);

	printf("The sum of the digits are %d\n" ,sum(num));
	return 0;
}


