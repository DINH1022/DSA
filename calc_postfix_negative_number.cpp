#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
struct Stack {
	int top;
	unsigned capacity;
	int* array;
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack
		= (struct Stack*)malloc(sizeof(struct Stack));

	if (!stack)
		return NULL;

	stack->top = -1;
	stack->capacity = capacity;
	stack->array
		= (int*)malloc(stack->capacity * sizeof(int));

	if (!stack->array)
		return NULL;

	return stack;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

int peek(struct Stack* stack)
{
	return stack->array[stack->top];
}

int pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--];
	return '$';
}

void push(struct Stack* stack, int op)
{
	stack->array[++stack->top] = op;
}

int evaluatePostfix(char* exp)
{
	struct Stack* stack = createStack(strlen(exp));
	int i;

	if (!stack)
		return -1;

	for (i = 0; exp[i]; ++i) {
		if (exp[i] == ' ')
			continue;

		
		else if (isdigit(exp[i])) {
			int num = 0;
            int flag=0;
            if(i!=0 && exp[i-1]=='-'){
                flag=1;
            }
			while (isdigit(exp[i])) {
				num = num * 10 + (int)(exp[i] - '0');
				i++;
			}
			i--;

            if(flag==1){
			    push(stack, -num);
            }
            else{
			    push(stack, num);
            }
		}
		else if ((exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/' || exp[i]=='^') && exp[i+1]==' '){
			int val1 = pop(stack);
			int val2 = pop(stack);

			switch (exp[i]) {
			case '+':
				push(stack, val2 + val1);
				break;
			case '-':
				push(stack, val2 - val1);
				break;
			case '*':
				push(stack, val2 * val1);
				break;
			case '/':
				push(stack, val2 / val1);
				break;
            case '^':
                push(stack,pow(val2,val1));
                break;
            }
		}
	}
	return pop(stack);
}
int main()
{
	string s="-100 3 + ";
    char exp[s.length()+1];
    strcpy(exp,s.c_str());
	printf("%d", evaluatePostfix(exp));
	return 0;
}
