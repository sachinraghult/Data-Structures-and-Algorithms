#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h>
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

int peek(struct Stack* stack) 
{ 
	return stack->array[stack->top]; 
} 

int pop(struct Stack* stack) 
{ 
	if (!isEmpty(stack)) 
		return stack->array[stack->top--] ; 
	return '$'; 
} 

void push(struct Stack* stack, int op) 
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
		if(exp[i]==' ')continue; 
		
		// If the scanned character is an 
		// operand (number here),extract the full number 
		// Push it to the stack. 
		else if (isdigit(exp[i])) 
		{ 
			int num; int sum = 0; int flag = 0; 
			
			//extract full number 
			while(isdigit(exp[i]))
			{ 
				num = (int)(exp[i] - '0') * pow(10 , flag);
				sum += num;
				flag++;
				i--;
			} 
			i++; 
			
			//push the element in the stack 
			push(stack,sum); 
		} 
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
			case '^': push(stack, pow(val2, val1)); break;
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

