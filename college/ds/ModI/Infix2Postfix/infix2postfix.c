#include <stdio.h>
#include <ctype.h>
#define MAX 128

typedef struct {char items[MAX]; int top;} Stack;

void push(Stack *s, char c) {s->items[++s->top] = c;}
char poop(Stack *s) {return s->items[s->top--];     }
char peek(Stack *s) {return s->items[s->top];       }

int precedence(char op) {
  return(op == '+' ||op == '-') ? 1 : (op == '*' || op == '/' ? 2 : 0);
}

void infix2postfix(const char *infix, char *postfix) {
  Stack s = {.top = -1};
  int j = 0;
  for (int i = 0; infix[i]; i++) { 
    char ch = infix[i];
    if (isalnum(ch))
      postfix[j++] = ch;
    else if(ch == '(')
      push(&s, ch);
    else if(ch == ')') {
      while (peek(&s) != '(') postfix[j++] = poop(&s);
      poop(&s);
    }  else { 
      while (s.top != -1 && precedence(peek(&s)) >= precedence(ch))
        postfix[j++] = poop(&s);
      push(&s, ch);
    }
  }
  while (s.top != -1) postfix[j++] = poop(&s);
  postfix[j] = '\0';
}

int main() {
  char infix[MAX], postfix[MAX];
  printf("enter the infix statemnt: ");
  scanf("%s", infix);
  infix2postfix(infix, postfix);
  printf("postfix is : %s\n", postfix);
}


