/**
 * @file
 * @brief This file contains basic stack operations using arrays.
 *
 * This file contains create, remove, push, pop, peer, print,
 * isEmpty and isFull operations on stack using arrays.
 * 
 * These functions should be called either from main or other functions
 * for successful operations.
 */

#include<stacks.h>

/** 
 * @brief Creates a new stack with array
 * 
 * This function creates a stack with array of given size
 * by allocating dynamic memory.
 * 
 * @param stack_ptr ptr to new stack.
 * @param size size of the stack.
 *
 * @return FAILURE, if no memory is present or size is less than 1
 *         SUCCESS, otherwise.
 */
int create_arr_stack(struct Stack *stack_ptr, int size)
{
	int ret;

	if (size < 1)
	{
		printf("Invalid size\n");
		ret = -EINVAL;
		goto err;
	}

	stack_ptr->size = size;
	stack_ptr->top = -1;
	stack_ptr->arr = (int *)calloc(stack_ptr->size, sizeof(int));

	if (!(stack_ptr->arr))
	{
		ret = -ENOMEM;
		goto err;
	}
	
	return 0;

err:
	return ret;
}

/**
 * @brief Removes the stack created
 *
 * This function removes the given stack after use
 * and free's associated memory.
 *
 * @param stack stack to be removed
 *
 * @return Success, on removal
 *         Failure, if stack is Empty or not created
 */
int remove_arr_stack(struct Stack *stack)
{
	isNullPtr(stack);
	isNullPtr(stack->arr);

	free(stack->arr);

	return 0;
}

/**
 * @brief Checks if stack is empty
 *
 * This function checks weather the given stack is empty or not.
 *
 *@param stack stack to be checked
 *
 *@return True, if stack is empty
 *        False, otherwise
 */
static bool is_arr_empty(struct Stack *stack)
{
	isNullPtr(stack);

	return stack->top == -1;
}

/**
  * @brief Checks if stack is full
  *
  * This function checks if given stack is full or not.
  *
  * @param stack stack to be checked
  *
  * @return True, if stack is full
  *         False, otherwise
  */
static bool is_arr_full(struct Stack *stack)
{
	isNullPtr(stack);

	return stack->top == stack->size - 1;
}

/**
 * @brief Push onto the stack
 *
 * This function pushes the given element onto the stack.
 *
 * @param stack stack to be pushed
 * @param element element to be pushed on stack
 *
 * @return Success, if element is pushed onto the stack.
 *         ENOMEM, if stack is full
 */
int push_arr(struct Stack *stack, int element)
{
	isNullPtr(stack);
	isNullPtr(stack->arr);

	if(is_arr_full(stack)) {
		printf("Stack is Full, cannot push more elements\n");
		return -ENOMEM;
	}

	stack->arr[++(stack->top)] = element;
	return 0;
}

/**
 * @brief Pop from the stack
 *
 * This function pops the stack by 1 element.
 *
 * @param stack stack to be popped
 *
 * @return Success, if element is popped from the stack.
 *         EINVAL, If stack is empty
 */
int pop_arr(struct Stack *stack)
{
	isNullPtr(stack);
	isNullPtr(stack->arr);

	if(is_arr_empty(stack)) {
		printf("Stack is empty, cannot do pop operation\n");
		return -EINVAL;
	}

	stack->arr[(stack->top)--] = 0;
	return 0;
}

/** @brief Peek stack
 * This function returns the valueon top of the stack.
 *
 * @param stack stack to be checked the top value.
 * @param val pointer to hold the value on top of the stack.
 *
 * @return Success, when value is returned on top of the stack.
 *         Failure, otherwise
 */
int peek_arr(struct Stack *stack, int *val)
{
	isNullPtr(stack);
	isNullPtr(val);
	isNullPtr(stack->arr);

	if(is_arr_empty(stack)) {
		*val = stack->arr[(stack->top) + 1];
		return 0;
	}

	*val = stack->arr[(stack->top)];
	return 0;
}

/**
 * @brief Print stack
 * This function prints the current stack elements to console.
 *
 * @param stack stack to be printed
 *
 * @return Success, if all elements are printed to console
 *         EINVAL, if stack is empty
 */
int print_arr_stack(struct Stack *stack)
{
	int itr;
	isNullPtr(stack);
	isNullPtr(stack->arr);

	for(itr = (stack->size)-1; itr > -1; itr--)
	{
		printf("%d\n" ,stack->arr[itr]);
	}

	return 0;
}
