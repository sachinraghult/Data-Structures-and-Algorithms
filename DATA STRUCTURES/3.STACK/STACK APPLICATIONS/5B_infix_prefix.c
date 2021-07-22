#include<stdio.h>
#include<string.h>
#define N 30

//STACK OPERATIONS.............................

static int top = -1;

struct stack{
	char arr[N];
}s;

int isFull()
{
	if(top == N-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isEmpty()
{
	if(top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(char val)
{
	if(!isFull())
	{
		top++;
		s.arr[top] = val;
	}
}

void pop()
{
	if(!isEmpty())
	{
		s.arr[top--] = 0;
	}
}

char peek()
{
	if(!isEmpty())
		return s.arr[top];
}

//INFIX POSTFIX CONVERSION REQUIRED FUNCTIONS.......................

int isOperand(char val)
{
	if((val >= 'A' && val <= 'Z') || (val >= 'a' && val <= 'z'))
	{
		return 1;
	}
	else
		return 0;
}

int isOperator(char val)
{
	if(val == '+' || val == '-' || val == '*' || val == '/' || val == '^')
	{
		return 1;
	}
	else
		return 0;
}

int precedence(char val)
{
	if(val == '^')
		return 3;
	else if(val == '*' || val == '/')
		return 2;
	else if(val == '+' || val == '-')
		return 1;
	else
		return -1;
}

//REVERSING THE INFIX EXPRESSION AND ALSO SWAP OF '(' AND ')' FUNCTION

void reverse(char in[N])
{
	strrev(in);
	
	int i;
	
	for(i = 0; in[i] ; i++)
	{
		if(in[i] == '(')
			in[i] = ')';
		else if(in[i] == ')')
			in[i] = '(';
	}
}

//INFIX POSTFIX CONVERSION FUNCTION

void infix_to_prefix(char in[N], char post[N])
{
	//REVERSE FUNCTION CALL
	
	reverse(in);
	
	int i;
	int j = 0;
	
	for(i = 0; in[i] ;i++)
	{
		if(isOperand(in[i]))
		{
			post[j++] = in[i];
		}
		else if(in[i] == '(')
		{
			push(in[i]);
		}
		else if(in[i] == ')')
		{
			while(!isEmpty() && peek() != '(')
			{
				post[j++] = peek();
				pop();
			}
			if(peek() == '(')
			{
				pop();
			}
		}
		else if(isOperator(in[i]))
		{
			if(isEmpty())
			{
				push(in[i]);
			}
			else if(!isEmpty())
			{
				if( precedence(in[i])> precedence(peek()) )
				{
					push(in[i]);
				}
				else if( precedence(in[i]) == precedence(peek())  && in[i] == '^' )
				{
					while( !isEmpty() && precedence(in[i]) == precedence(peek()) )
					{
						post[j++] = peek();
						pop();
					}
					push(in[i]);
				}
				else if( precedence(in[i]) == precedence(peek()) )
				{
					push(in[i]);
				}
				else
				{
					while( !isEmpty() && precedence(in[i]) < precedence(peek()) )
					{
						post[j++] = peek();
						pop();
					}
					push(in[i]);
				}
			}
		}
	}
	
	while(!isEmpty())
	{
		post[j++] = peek();
		pop();
	}
	post[j] = '\0';
	
	//ATLAST REVERSE THE RESULTANT POSTFIX EXPRESSION
	
	strrev(post);
}


int main()
{
	char in[N], post[N];
	
	printf("Infix Expression : ");
	scanf("%s",in);
	
	infix_to_prefix(in, post);
	
	printf("\nPrefix Expression : %s",post);
	
	return 0;
}
