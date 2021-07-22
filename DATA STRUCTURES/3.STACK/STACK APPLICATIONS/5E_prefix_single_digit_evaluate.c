#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 
 
struct Stack 
{ 
	int top; 
	unsigned capacity; 
	int* array; 
}; 

// Stack Operations 

struct Stack* createStack( unsigned capacity ) 
{ 
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 

	if (!stack) return NULL; 

	stack->top = -1; 
	stack->capacity = capacity; 
	stack->array = (int*) malloc(stack->capacity * sizeof(int)); 

	if (!stack->array) return NULL; 

	return stack; 
} 

int isEmpty(struct Stack* stack) 
{ 
	return stack->top == -1 ; 
} 

char peek(struct Stack* stack) 
{ 
	return stack->array[stack->top]; 
} 

char pop(struct Stack* stack) 
{ 
	if (!isEmpty(stack)) 
		return stack->array[stack->top--] ; 
	return '$'; 
} 

void push(struct Stack* stack, char op) 
{ 
	stack->array[++stack->top] = op; 
} 

//Evaluation of prefix

int evaluatePrefix(char* exp) 
{ 
	struct Stack* stack = createStack(strlen(exp)); 
	int i; 

	if (!stack) return -1; 

	for (i = strlen(exp); i >= 0 ; --i) 
	{ 
		// If the scanned character is an operand (number here), 
		// push it to the stack.
		 
		if (isdigit(exp[i])) 
			push(stack, exp[i] - '0'); 

		// If the scanned character is an operator, pop two 
		// elements from stack apply the operator 
		else
		{ 
			int val2 = pop(stack); 
			int val1 = pop(stack); 
			switch (exp[i]) 
			{ 
			case '+': push(stack, val2 + val1); break; 
			case '-': push(stack, val2 - val1); break; 
			case '*': push(stack, val2 * val1); break; 
			case '/': push(stack, val2/val1); break; 
			} 
		} 
	} 
	return pop(stack); 
} 


int main() 
{
	char exp[30];
	
	printf("Prefix expression : ");
	
	int ch, i = 0;
	
	while((ch = getchar()) != '\n')
		if(i < 30)
			exp[i++] = ch;
	exp[i] = '\0';
	 
 
	printf ("Prefix evaluation: %d", evaluatePrefix(exp)); 
	return 0; 
} 

