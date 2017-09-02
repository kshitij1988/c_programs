#include<stdio.h>
#include<stdlib.h>

int main()
{
	int M,N;

	printf("Enter two numbers to be swapped\n");
	scanf("%d%d" ,&M,&N);
	printf("Original values are :\tM: %d\tN: %d\n",M,N);

	M=M+N;
	N=M-N;
	M=M-N;

	printf("Swapped values are :\tM: %d\tN: %d\n",M,N);

	return 0;
}
