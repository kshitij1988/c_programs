#include "stacks.h"

#define NUM_BRACKETS 3

static const char openingBrackets[NUM_BRACKETS] = {'[', '(', '{'};
static const char closingBrackets[NUM_BRACKETS] = {']', ')', '}'};

static bool isOpeningBracket(char bracket)
{
	int itr;

	for(itr=0; itr < NUM_BRACKETS; itr++)
	{
		if(bracket == openingBrackets[itr])
			return true;
	}

	return false;
}

static bool isClosingBracket(char bracket)
{
	int itr;

	for(itr=0; itr < NUM_BRACKETS; itr++)
	{
		if(bracket == closingBrackets[itr])
			return true;
	}

	return false;
}

static bool isMatching(char openB, char closeB)
{
	if((openB == '[') && (closeB == ']'))
		return true;
	else if((openB == '(') && (closeB == ')'))
		return true;
	else if((openB == '{') && (closeB == '}'))
		return true;
	else
		return false;
}

int isParenthesisBalanced(const char *str)
{
	struct Node *stack = NULL;
	int itr = 0;

	isNullPtr(str);

	while(str[itr] != '\0')
	{
		
		if(!(isClosingBracket(str[itr])) &&
		   !(isOpeningBracket(str[itr])))
			return -EINVAL;
		else if((stack != NULL) &&
		        (isClosingBracket(str[itr])) &&
		        (isOpeningBracket(stack->data)) &&
		        (isMatching(stack->data, str[itr])))
				pop_LL(&stack);
		else
			push_LL(&stack, (int)str[itr]);
		itr++;
	}

	return (stack == NULL);
}
