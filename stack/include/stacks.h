#ifndef STACKS_H
#define STACKS_H

#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<stdbool.h>
#include<errno.h>

struct Stack {
	int top;
	int size;
	int *arr;
};

struct Node {
	int data;
	struct Node *next;
};

static inline int isNullPtr(const void *ptr)
{
	if(!ptr) {
		perror("Invalid operation, Null ptr detected\n");
		return errno;
	}

	return 0;
}

int create_arr_stack(struct Stack *stack_ptr, int size);
int remove_arr_stack(struct Stack *stack);
int push_arr(struct Stack *stack, int element);
int pop_arr(struct Stack *stack);
int peek_arr(struct Stack *stack, int *val);
int print_arr_stack(struct Stack *stack);
int push_LL(struct Node **top, int data);
int pop_LL(struct Node **top);
int peek_LL(struct Node *top, int *val);
int print_LL_stack(struct Node *top);
int isParenthesisBalanced(const char *str);
int next_greater_element_wo_stack(int *arr, size_t size);
int next_greater_element_w_stack(int *arr, size_t size);
#endif //STACKS_H
