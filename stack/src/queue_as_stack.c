#include "stacks.h"

static bool isEmpty_QAS(struct Node *stack)
{
	return (stack == NULL);
}

int enqueue_QAS(struct Node **stack, int element)
{
	isNullPtr(stack);
	struct Node *top = *stack;
	struct Node *new_top = NULL;
	int ret = 0;

	ret = push_LL(stack, element);
	if(ret)
		return ret;

	if(!top)
		return ret;

	new_top = *stack;
	
	while((*stack)->next)
	{
		*stack = (*stack)->next;
	}
	
	(*stack)->next = new_top;
	new_top->next = NULL;
	*stack = top;
	return ret;
}

int dequeue_QAS(struct Node **stack)
{
	isNullPtr(stack);
	int ret = 0;

	if(isEmpty_QAS(*stack))
	{
		printf("Cannot Dequeue an empty queue\n");
		return -EINVAL;
	}

	ret = pop_LL(stack);
	return ret;
}

int getFront_QAS(struct Node *stack, int *front)
{
	int ret = 0;

	if(isEmpty_QAS(stack))
	{
		printf("Cannot get front element of an empty queue\n");
		return -EINVAL;
	}
	ret = peek_LL(stack, front);
	return ret;
}

int getRear_QAS(struct Node *stack, int *rear)
{
	int ret = 0;
	struct Node *current = stack;

	if(isEmpty_QAS(stack))
	{
		printf("Cannot get rear element of an empty queue\n");
		return -EINVAL;
	}

	while(current->next)
		current = current->next;
	
	ret = peek_LL(current, rear);
	return ret;
}

int print_QAS(struct Node *stack)
{
	int ret = 0;

	if(isEmpty_QAS(stack))
	{
		printf("Current queue is empty, no data to print\n");
		return 0;
	}

	ret = print_LL_stack(stack);
	return ret;
}

