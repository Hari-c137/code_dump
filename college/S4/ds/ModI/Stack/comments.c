#include <stdio.h>

#define MAX 128 // swap MAX field before compilation with the given value

typedef struct {int items[MAX]; int top;} Stack; // declaring a structure for stack and aliasing it as 'Stack' through typedef

// single line stack operation with error checking 
//  push doesn't return anything, takes stack_trace + pushed element, checks overflow and push to stack + increment top after push
    void push(Stack *s, int val) {s->top <= MAX - 1 ? s->items[++s->top] = val : printf("Overflow Detected") ;}
//  pop returns the popped value, takes the stack_trace only, checks underflow and pop value and decrements top by 1
    int   pop(Stack *s) {return s->top >= 0 ? s->items[s->top--] : printf("Underflow Detected \n") ;}
//  pek returns the peeked value, takes teh stack_trace only, chceks ifempty get top value without decrements afterwards
    int   pek(Stack *s) {return s->top >= 0 ? s->items[s->top] : printf("Stack is Empty \n") ;}
// display all the stored elements, increments works by setting the starting as top value then decrementing top one minus one using the condition that top still high than zero and print statement is used to print each index through 'i'
    void show(Stack *s) { for(int i = s->top; i >= 0; i--) printf("%d\n", s->items[i]); }

void main() {
  Stack s = {.top = -1}; int ch, val;// create an instance 's' of stack structure and adds top variable the value of -1 indicating empty
  while(1) { // an infinite while loop is initialized by setting the condition as 1 similar to boolean true
    printf("1. INSERT  2.DELETE  3.HIGH  4.DISPLAY  5.EXIT "); scanf("%d", &ch);
//  value is read from tty and added as parameter the previously defined push(); push(<stack_address>,<added_element>)
    if(ch == 1) {printf("VALUE: "); scanf("%d", &val); push(&s, val); }
    else if(ch == 2) { val = pop(&s); printf("Popped Value: %d \n",val); }
    else if(ch == 3) { val = pek(&s); printf("Peeked Value: %d \n",val); }
    else if(ch == 4) show(&s);
// stop the infinite while loop by breaking out of the loop alltogether
    else if(ch == 5) break;
    else printf("Invalid Statement!\n");
  }
}

