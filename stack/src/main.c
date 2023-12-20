#include "stacks.h"

static int stack_impl_array(void)
{
	struct Stack stack;
	unsigned int size = 5;
	int peek_stack = 0;

	create_arr_stack(&stack, size);
	
	peek_arr(&stack, &peek_stack);
	printf("Current top of the stack is %d\n" ,peek_stack);
	printf("Original stack with size %d and 5 values\n" ,size);
	push_arr(&stack, 12);
	push_arr(&stack, -9);
	push_arr(&stack, 67);
	push_arr(&stack, 5);
	push_arr(&stack, 8);
	print_arr_stack(&stack);

	peek_arr(&stack, &peek_stack);
	printf("Current top of the stack is %d\n" ,peek_stack);
	printf("stack with size %d and 2 pops\n" ,size);
	pop_arr(&stack);
	pop_arr(&stack);
	print_arr_stack(&stack);

	peek_arr(&stack, &peek_stack);
	printf("Current top of the stack is %d\n" ,peek_stack);
	printf("stack with size %d and 2 pushs\n" ,size);
	push_arr(&stack, 23);
	push_arr(&stack, 134);
	print_arr_stack(&stack);

	peek_arr(&stack, &peek_stack);
	printf("Current top of the stack is %d\n" ,peek_stack);
	printf("stack with size %d and 6th invalid push\n" ,size);
	push_arr(&stack, 19);
	print_arr_stack(&stack);

	return 0;
}

static int stack_impl_linkedList(void)
{
	struct Node *stack = NULL;
	int peek_stack = 0;

	printf("Trying invalid Pop operation\n");
	pop_LL(&stack);
	printf("Trying invalid Peek operation\n");
	peek_LL(stack, &peek_stack);
	printf("Trying invalid Print operation\n");
	print_LL_stack(stack);

	printf("Pushing 3 elements onto the stack\n");
	push_LL(&stack, 730);
	push_LL(&stack, 715);
	push_LL(&stack, 745);
	peek_LL(stack, &peek_stack);
	printf("Current top of the stack is %d\n" ,peek_stack);
	print_LL_stack(stack);

	printf("Pop 1 element from the stack\n");
	pop_LL(&stack);
	peek_LL(stack, &peek_stack);
	printf("Current top of the stack is %d\n" ,peek_stack);
	print_LL_stack(stack);

	return 0;
}

int main(void)
{
	int ret = 0;

	ret = stack_impl_array();
	if(ret)
	{
		printf("stack implementation with arrays failed\n");
		return ret;
	}

	ret = stack_impl_linkedList();
	if(ret)
	{
		printf("stack implementation with linkedLists failed\n");
		return ret;
	}

	return 0;
}
