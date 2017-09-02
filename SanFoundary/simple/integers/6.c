#include<stdio.h>

int main()
{
	int m,n;

	printf("Enter two values to be compared\n");
	scanf("%d%d" ,&m,&n);

	if(m == n)
		printf("Value entered by you are equal\n");
	else
		printf("Value's are not equal\n");

	return 0;
}
