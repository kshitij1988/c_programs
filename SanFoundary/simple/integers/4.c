#include<stdio.h>
#include<stdlib.h>

int main()
{
	int start,end,i,sum=0,count=1;
	int *mem=NULL,*new_mem=NULL;
	printf("Enter the start and end of range, to find number divisible by 5\nStart:\t");
	scanf("%d" ,&start);
	printf("End:\t");
	scanf("%d" ,&end);

	mem = malloc(sizeof(int));

	for(i=start;i<=end;i++)
	{
		if(i%5 == 0)
		{
			mem[count-1] = i;
			sum = sum+i;
			new_mem = (int *)realloc(mem, sizeof(int)*(++count));
			mem = new_mem;
		}
	}
	
	printf("Numbers that are divisible by 5 in the range specified by you are:\n");
	
	for(i=0;i<count-1;i++)
	{
		printf("%d\n" ,mem[i]);
	}
	
	printf("The sum of all these numbers is: %d\n" ,sum);
	return 0;
}


