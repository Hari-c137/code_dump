#include <stdio.h>
#include <ctype.h>
#define MAX 128

typedef struct { int items[MAX]; int top;} Stack;

void push(Stack *s, int val) {s->items[++s->top] = val;}
int   pop(Stack *s) {return s->items[s->top--];}

int post_eval(char *postfix) {

  Stack s = {.top = -1};
  for (int i = 0; postfix[i]; i++) {
    char ch = postfix[i];
    if (isdigit(ch)) 
      push(&s, ch - '0');
    else {
      int b = pop(&s), a = pop(&s);
      switch (ch) {
        case '+': push(&s, a + b); break;
        case '-': push(&s, a - b); break;
        case '*': push(&s, a * b); break;
        case '/': push(&s, a / b); break;
      }
    }
  }
return pop(&s);
}

int main() {
char postfix[MAX];
printf("enter the postfix expression: \n"); scanf("%s", postfix);
printf("Result: %d\n", post_eval(postfix));
}

