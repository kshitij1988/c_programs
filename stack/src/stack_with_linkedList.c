/**
* @file
* @brief This file contains basic stack operations using linked lists.
*
* This file contains push, pop, peek, print and is_list_empty operation
* on stacks using linkedlists.
*
* These functions should be called wither from main or other functions
* for successful operations.
*/
#include<stacks.h>

/**
 * @brief Checks if stack is empty
 *
 * This function checks the given stack has any data or not.
 *
 * @param top pointer to top of the stack
 *
 * @return TRUE, if stack is empty
 *         FALSE, otherwise
 */
static int is_list_empty(struct Node *top)
{
	return (top == NULL);
}

/**
 * @brief Push to the stack
 *
 * This function pushes the new element on top of existing stack
 *
 * @param top pointer containing address of top of the stack
 * @param data element to be pushed onto the stack
 *
 * @return Success, if new element is pushed onto the stack
 *         Failure, on error conditions.
 */
int push_LL(struct Node **top, int data)
{
	isNullPtr(top);

	struct Node *new_node = NULL;

	new_node = (struct Node *)malloc(sizeof(struct Node));
	if(!new_node)
	{
		return -ENOMEM;
	}

	new_node->data = data;
	new_node->next = *top;
	*top = new_node;

	return 0;
}

/**
 * @brief Pop from the stack
 *
 * This functions pops the top element from the stack
 *
 * @param top pointer containing address of top of the stack
 *
 * @return Success, if element is popped from the stack
 *         Failure, on error conditions.
 */
int pop_LL(struct Node **top)
{
	isNullPtr(top);
	struct Node *current_top = *top;

	if(is_list_empty(*top))
	{
		printf("Cannot pop from empty stack\n");
		return -EINVAL;
	}

	*top = (*top)->next;
	free(current_top);

	return 0;
}

/**
 * @brief Peek in the stack
 *
 * This functions peeks the stack and updates the value
 *
 * @param top pointer to stack
 * @param val pointer to value which is updated with top of the stack
 *
 * @return Success, if peek in the stack
 *         Failure, on error conditions.
 */
int peek_LL(struct Node *top, int *val)
{
	isNullPtr(val);

	if(is_list_empty(top))
	{
		printf("Cannot peek into empty stack\n");
		return -EINVAL;
	}

	*val = top->data;
	return 0;
}

/**
 * @brief Print the stack
 *
 * This function dumps  the current stack values on console.
 *
 * @param top pointer containing address of top of the stack
 *
 * @return Success, when all elements of stack are printed
 */
int print_LL_stack(struct Node *top)
{
	struct Node *current = top;

	if(is_list_empty(top))
	{
		printf("Current stack is empty, no data to print\n");
		return 0;
	}

	printf("Current values are:\n");
	while(current != NULL)
	{
		printf("%d\n" ,current->data);
		current = current->next;
	}
	return 0;
}
