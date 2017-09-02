#include<stdio.h>
#include<stdlib.h>

#define MASK 0x1

static char* even_odd(int num)
{
	if(num == 1)
		return "Neither EVEN nor ODD";
	else if(num & MASK)
		return "ODD";
	else
		return "EVEN";
}

int main()
{
	int num;

	printf("Enter a number to be categorised as even or odd\n");
	scanf("%d" ,&num);

	printf("The number %d is %s\n" ,num,even_odd(num));
}
