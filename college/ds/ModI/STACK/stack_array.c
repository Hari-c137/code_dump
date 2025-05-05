#include <stdio.h>
#define MAX 128

typedef struct { int items[MAX]; int top; } IntStack; // create a callname 'IntStack' for easier reference to struct


// documention for this part of code is already provided in postfix section
void push(IntStack *s, int v) { s->top < MAX - 1 ? s->items[++s->top] = v : printf("Overflow\n"); } 
int pop(IntStack *s) { return s->top >= 0 ? s->items[s->top--] : (printf("Underflow\n"), -1); }
int peek(IntStack *s) { return s->top >= 0 ? s->items[s->top] : (printf("Empty\n"), -1); }
void display(IntStack *s) { for(int i = s->top; i >= 0; i--) printf("%d\n", s->items[i]); }

int main() {
  IntStack s = {.top = -1}; int ch, val; // inialize stack 's' through instance of the structure 'IntStack' and set a var 'top' with -1 (MT)
  while (1) { // inifinity while loop mutha-fuckassss
    printf("1.Push 2.Pop 3.Peek 4.Display 5.Exit: "); scanf("%d", &ch);
    if (ch == 1) { printf("Val: "); scanf("%d", &val); push(&s, val); }
    else if (ch == 2) { val = pop(&s); if (val != -1) printf("Popped: %d\n", val); }
    else if (ch == 3) { val = peek(&s); if (val != -1) printf("Top: %d\n", val); }
    else if (ch == 4) { display(&s); }
    else if (ch == 5) break;
    else printf("Invalid\n");
  }
}

