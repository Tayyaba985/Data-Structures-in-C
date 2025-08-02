#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "stack_functions.h"
#define MAX_EXPRESSION_SIZE 100
struct element pop(struct node ** top)
{
    struct element temp = (*top)->data;   /// I copy the data at the top node into a temporary variable

    struct node * ptr_temp = (*top)->next;

    free(*top);
    *top = ptr_temp;

    return(temp);

}

void push(struct node ** top, struct element new_data)
{
    struct node * new_node = (struct node *) malloc(sizeof(struct node));

    new_node->data = new_data;      /// I can assign one struct to another if the type is the same

    new_node->next = * top;
    * top = new_node;
}

void reverse_num_array(int * nu_array, int arr_size)
{
    struct node * top = NULL;
    struct element d4;
    struct element d5;
    d4.d= num_array[arr_size];
    for (int i=0; i<arr-size; i++)
    {
        d4.d= num_array[i];
        push(&top,d4);
    }
    for (int i=0; i<arr_size; i++)
    {
        d5=pop(&top);
        num_array[i]= d5.d;
    }
}

int isBalanced(char * ptr_array)
{
    struct element d7;
    for(int i=0;ptr_array!=\0;i+=)
    {
        if(ptr_array[i]=='(' || ptr_array[i]='[' || ptr_array[i]=='{')
            push(&d7,exp[i]);
        else if(ptr_array[i]==')' || ptr_array[i]==']' || ptr_array[i]=='}')
            pop(d7);
            if (d7 == NULL)
                return 0;
            else if (!isMatchingPair(pop(&d7), ptr_array[i]))
                return 0;
    }
}

bool isMatchingPair(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

void infixToPostfix(char *src, char *dst)
{
    if (!isBalanced(src))
        {printf("Unbalanced parentheses in the expression.\n");
         return;}
    int src_len = strlen(src);
    char stack[MAX_EXPRESSION_SIZE];
    int stack_top = -1;
    int j = 0;
    for (int i = 0; i < src_len; i++)
    {
        char currentChar = src[i];
    if (currentChar >= '0' && currentChar <= '9')
        {dst[j++] = currentChar;
        }
    else if (isOperator(currentChar))
        {while (stack_top >= 0 && isOperator(stack[stack_top]) &&
          precedence(stack[stack_top]) >= precedence(currentChar))
          {dst[j++] = stack[stack_top--];}
          stack[++stack_top] = currentChar;
        }
    else if (currentChar == '(')
        { stack[++stack_top] = currentChar;}
    else if (currentChar == ')')
        { while (stack_top >= 0 && stack[stack_top] != '(')
        {dst[j++] = stack[stack_top--];}
    if (stack_top >= 0 && stack[stack_top] == '(')
        {stack_top--;}
    else {printf("Unbalanced parentheses in the expression.\n");
          return;}
        }
    }

    while (stack_top >= 0)
        {if (stack[stack_top] == '(')
        {printf("Unbalanced parentheses in the expression.\n");
         return;}
        dst[j++] = stack[stack_top--];
        }
    dst[j] = '\0';
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    }
    return 0;
}

