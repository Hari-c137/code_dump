#include <stdio.h>
#include <ctype.h>

#define MAX 128

// implementing stack Char & Int for ITF and EPE
typedef struct {char items[MAX]; int top; } CharStack; // typedef used to alias enter structure under the name CharStack
typedef struct {int items[MAX]; int top; } IntStack;  // same shit here but for IntStack


// functions for stack operations 
void pushChar(CharStack *s, char c) { s->items[++s->top] = c; } // increments the top of stack and then access the top
char popChar(CharStack *s) { return s->items[s->top--]; } // return the top and then decrements
char peekChar(CharStack *s) { return s->items[s->top]; } // return the topmost value
void pushInt(IntStack *s, int val) { s->items[++s->top] = val; } // increments the top of stack and then access the top
int popInt(IntStack *s) { return s->items[s->top--]; } // return the top and then decrements


int precedence(char op) { // takes in operator 'op' char and return its corresponding precedence
  return (op == '+' || op == '-') ? 1 : (op == '*' || op == '/' ? 2 : 0);
}

void ITF(const char *infix, char *postfix) { // 2 parameters taken,first will carry infix exp to the function and 2 parameter will inherit the postfix exp from the function
  CharStack s = {.top = -1};
  int j = 0;
  for (int i = 0; infix[i]; i++) {
    char ch = infix[i];
    if (isalnum(ch))
      postfix[j++] = ch;
    else if (ch == '(')
        pushChar(&s, ch);
    else if (ch == ')') {
      while (peekChar(&s) != '(') postfix[j++] = popChar(&s);
      popChar(&s);
    } else {
      while (s.top != -1 && precedence(peekChar(&s)) >= precedence(ch))
        postfix[j++] = popChar(&s);
      pushChar(&s, ch);
    }
  }
  while (s.top != -1) postfix[j++] = popChar(&s);
  postfix[j] = '\0';
}

int EPE(const char *postfix) { // evaluate postfix expression to its corresponding value 
  IntStack s = {.top = -1}; // initialize a structure 's' with top and make the top -1 meaning empty
  for (int i = 0; postfix[i]; i++) { // check each postfix values using forloop
    char ch = postfix[i]; 
    if (isdigit(ch)) // if the value is an number it will get pushed to the stack
      pushInt(&s, ch - '0');
    else  { // if it is an operator, it will pop 2 value as 'a' and 'b' and do calculation on it depending on its case
      int b = popInt(&s), a = popInt(&s);
      switch (ch) {
        case '+': pushInt(&s, a + b); break;
        case '-': pushInt(&s, a - b); break;
        case '*': pushInt(&s, a * b); break;
        case '/': pushInt(&s, a / b); break;
      }
    }
  }
  return popInt(&s);

}

int main() {

  char infix[MAX], postfix[MAX];
  printf("enter infix expression: ");
  scanf("%s", infix);

  ITF(infix,postfix); // input is infix and the process output will be stored to second parameter (postfix)
  printf("Postfix: %s\n", postfix); // print the now_populated postfix array
  printf("Result : %d\n", EPE(postfix)); 
}
