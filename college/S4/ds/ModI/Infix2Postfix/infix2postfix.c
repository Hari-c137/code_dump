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
  Stack s = {.top = -1}; // initialize an instance of stack structure called 's' and populate its content 'top' with a value of -1 meaning mt
  int j = 0; // used for adding to the postfix character array
  for (int i = 0; infix[i]; i++) { // start a forloop that runs from 0 to end of infix's last index 
    char ch = infix[i]; // during each run of forloop the current value at that index is stored at 'ch' of char datatype
    if (isalnum(ch)) // check whether the ch obtained in the current instance of forloop is a operand (number)
      postfix[j++] = ch; // if the above condition is true then it will add th ch (operand) to the postfix character array
    else if(ch == '(') // check whether the ch obtained in the current instance of forloop is an open bracket
      push(&s, ch); // if the above condition is trye then it will push the bracket inside 'ch' to the stack
    else if(ch == ')') { //  check whether the ch obtained in the current instance of foreloop is a closing bracket 
      while (peek(&s) != '(') postfix[j++] = poop(&s); // if true, check peek != opening bracket and pop the last value at structure and store that poped value on postfix char array by increamenting is j++
      poop(&s); // then it pops the stack array again (i dont know fucking why.. welp!!)
    }  else { // from earlier while loop for opening is not true then i must a fucking opertor.. therefore we use over precedence() here
      while (s.top != -1 && precedence(peek(&s)) >= precedence(ch)) // only when the top is not MT and precedence of peek value is higher or equal to precedence of ch then value is poped from the stack and added to postfix array
        postfix[j++] = poop(&s);
      push(&s, ch); // then the ch is possed to stack
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


