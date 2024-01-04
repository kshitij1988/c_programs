#include "stacks.h"

int next_greater_element_wo_stack(int *arr, size_t size)
{
	isNullPtr(arr);
	unsigned int i_out;
	unsigned int i_in;

	if(size < 1)
		return -EINVAL;
	if(size == 1)
	{
		printf("-1 is NGE for %d\n", arr[size-1]);
		return 0;
	}
	for(i_out=0; i_out<size; i_out++)
	{
		i_in = i_out + 1;
		for(; i_in<size; i_in++)
		{
			if(arr[i_in] > arr[i_out])
			{
				printf("%d is NGE for %d\n", arr[i_in], arr[i_out]);
				break;
			}
		}
		if(i_in == size)
			printf("-1 is NGE for %d\n", arr[i_out]);
	}

	return 0;
}

int next_greater_element_w_stack(int *arr, size_t size)
{
	isNullPtr(arr);
	struct Node *walk = NULL;
	struct Node *stack = NULL;
	unsigned int next;
	int ret;

	if(size < 1)
		return -EINVAL;
	if(size == 1)
	{
		printf("NGE for %d is -1\n" ,arr[size-1]);
		return 0;
	}
	for(next=1; next<=size; next++)
	{
		ret = push_LL(&stack, arr[next-1]);
		if(ret)
			return ret;
		walk = stack;
		while(walk)
		{
			if (next == size)
			{
				printf("NGE for %d is -1\n" ,stack->data);
				pop_LL(&stack);
				walk = stack;
			}
			else if(arr[next] > stack->data)
			{
				printf("NGE for %d is %d\n" ,stack->data, arr[next]);
				pop_LL(&stack);
				walk = stack;
			}
			else if(walk)
				walk = walk->next;
		}
	}

	return 0;
}

